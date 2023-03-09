/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:07:39 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 13:15:59 by lboulatr         ###   ########.fr       */
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

//----------------------------- COMMANDS -------------------------------------

void		command_manager(int status, int *pipefd, char **argv, char **envp);

#endif
