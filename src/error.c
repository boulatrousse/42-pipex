/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:52:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/10 13:36:02 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	display_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	error_cmd(char *str, char **cmd)
{
	write(2, str, ft_strlen(str));
	free_array(cmd);
	exit(EXIT_FAILURE);
}

void	exec_error(char *str)
{
	ft_putstr_fd("Command not found : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	close_fd(3);
}

void	free_cmd(char **cmd)
{
	close_fd(0);
	free_array(cmd);
	exit(EXIT_FAILURE);
}

void	print_error(char *str, char *cmd)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", 2);
}
