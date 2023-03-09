/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:07:39 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 17:06:49 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "../libft/include/libft.h"

# define STDIN STDIN_FILENO
# define STDOUT STDOUT_FILENO

//--------------------------- UTILS ------------------------------------------

void		free_array(char **array);
void		ft_error(int x);
char		**path_envp(char **envp);
char		**ft_command(char *str);
char		*valid_path(int i, char **envp, char *str);
void		close_fd(int i);
void		display_error(char *str);
void		error_cmd(char *str, char **cmd);
void		exec_error(void);
void		free_cmd(char **cmd);

//----------------------------- COMMANDS -------------------------------------

void		command_manager(int *pipefd, char **argv, char **envp);
int			check_command(char *arg, char **cmd);

#endif
