/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:42:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 13:06:38 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fd(int i)
{
	while (i <= 1023)
	{
		close(i);
		i++;
	}
}

void	close_all(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	else
		return ;
}

void	display_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
