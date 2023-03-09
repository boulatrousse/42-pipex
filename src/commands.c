/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:04:25 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 13:14:56 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_command(char *arg, char **cmd)
{
	if (ft_strlen(arg) == 0)
		return (ft_putstr_fd("Permission denied.\n", 2), -1);
	if (arg[0] == ' ')
		return (ft_putstr_fd("Command not found.\n", 2), -1);
	if (access(cmd[0], F_OK) == 0)
		return (0);
	if (cmd[0])
		if (ft_strnstr(cmd[0], "./", 2) != NULL)
			return (ft_putstr_fd("No such file or directory\n", 2), -1);
	return (0);
}

static void	first_command(int fd_in, int *pipefd, char **argv, char **envp)
{
	char	**cmd;

	if (fd_in < 0)
		perror("FD");
	cmd = ft_command(argv[2]);
	if (!cmd)
		exit(EXIT_FAILURE);
	if (check_command(argv[2], cmd) == 0)
	{
		close(pipefd[0]);
		if (dup2(fd_in, STDIN_FILENO) < 0 || dup2(pipefd[1], STDOUT_FILENO) < 0)
			return (free_array(cmd));
		close_fd(3);
		close(fd_in);
		if (cmd[0] && valid_path(0, envp, cmd[0]) != NULL)
			execve(valid_path(0, envp, cmd[0]), cmd, envp);
		ft_putstr_fd("Command not found.\n", 2);
		close_fd(3);
	}
	close_fd(3);
	free_array(cmd);
	exit(EXIT_FAILURE);
}

static void	second_command(int fd_out, int *pipefd, char **argv, char **envp)
{
	char	**cmd;

	cmd = ft_command(argv[3]);
	if (!cmd)
		exit(EXIT_FAILURE);
	if (check_command(argv[3], cmd) == 0)
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN) < 0 || dup2(fd_out, STDOUT) < 0)
			return (free_array(cmd));
		close_fd(3);
		close(fd_out);
		if (cmd[0] && valid_path(0, envp, cmd[0]) != NULL)
			execve(valid_path(0, envp, cmd[0]), cmd, envp);
		ft_putstr_fd("Command not found.\n", 2);
		close_fd(3);
	}
	close_fd(3);
	free_array(cmd);
	exit(EXIT_FAILURE);
}

void	command_manager(int status, int *pipefd, char **argv, char **envp)
{
	int		fd_in;
	int		fd_out;
	pid_t	c_id1;
	pid_t	c_id2;

	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd_out < 0)
		return (perror("FD"));
	c_id1 = fork();
	if (c_id1 < 0)
		return (perror("FORK"));
	if (c_id1 == 0)
		first_command(fd_in, pipefd, argv, envp);
	c_id2 = fork();
	if (c_id2 < 0)
		return (perror("FORK"));
	if (c_id2 == 0)
		second_command(fd_out, pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	close(STDIN);
	close(STDOUT);
	waitpid(c_id1, &status, 0);
	waitpid(c_id2, &status, 0);
}
