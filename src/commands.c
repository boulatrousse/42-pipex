/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:04:25 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/10 13:25:21 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_one(int *fd, int *pipefd, char **argv, char **envp);
static void	child_two(int *fd, int *pipefd, char **argv, char **envp);
static void	first_command(int *fd, int *pipefd, char **argv, char **envp);
static void	second_command(int *fd, int *pipefd, char **argv, char **envp);

void	command_manager(int *pipefd, char **argv, char **envp)
{
	int		fd[2];
	int		status;

	child_one(fd, pipefd, argv, envp);
	child_two(fd, pipefd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	close(STDIN);
	close(STDOUT);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}

static void	child_one(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	c_id;

	c_id = fork();
	if (c_id < 0)
		perror("FORK");
	if (c_id == 0)
		first_command(fd, pipefd, argv, envp);
}

static void	child_two(int *fd, int *pipefd, char **argv, char **envp)
{
	pid_t	c_id;

	c_id = fork();
	if (c_id < 0)
		perror("FORK");
	if (c_id == 0)
		second_command(fd, pipefd, argv, envp);
}

static void	first_command(int *fd, int *pipefd, char **argv, char **envp)
{
	char	**cmd;

	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] < 0)
		perror(argv[1]);
	cmd = ft_command(argv[2]);
	if (!cmd)
		exit(EXIT_FAILURE);
	close(pipefd[0]);
	if (check_command(argv[2], cmd) == 0)
	{
		if (dup2(fd[0], STDIN) < 0 || dup2(pipefd[1], STDOUT) < 0)
			return (free_array(cmd));
		close_fd(3);
		close(pipefd[1]);
		close(fd[0]);
		if (cmd[0] && valid_path(0, envp, cmd[0]) != NULL)
			execve(valid_path(0, envp, cmd[0]), cmd, envp);
		exec_error(cmd[0]);
	}
	free_cmd(cmd);
}

static void	second_command(int *fd, int *pipefd, char **argv, char **envp)
{
	char	**cmd;

	fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd[1] < 0)
		perror(argv[4]);
	cmd = ft_command(argv[3]);
	if (!cmd)
		exit(EXIT_FAILURE);
	close(pipefd[1]);
	if (check_command(argv[3], cmd) == 0)
	{
		if (dup2(pipefd[0], STDIN) < 0 || dup2(fd[1], STDOUT) < 0)
			return (free_array(cmd));
		close_fd(3);
		close(pipefd[0]);
		close(fd[1]);
		if (cmd[0] && valid_path(0, envp, cmd[0]) != NULL)
			execve(valid_path(0, envp, cmd[0]), cmd, envp);
		exec_error(cmd[0]);
	}
	free_cmd(cmd);
}
