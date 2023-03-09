/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:52:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 17:05:13 by lboulatr         ###   ########.fr       */
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

void	exec_error(void)
{
	ft_putstr_fd("Command not found.\n", 2);
	close_fd(3);
}

void	free_cmd(char **cmd)
{
	close_fd(3);
	free_array(cmd);
	exit(EXIT_FAILURE);
}
