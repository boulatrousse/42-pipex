/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:42:37 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 13:04:04 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int			pipefd[2];

	if (argc == 5)
	{
		if (pipe(pipefd) < 0)
			display_error("Pipe error.\n");
		command_manager(0, pipefd, argv, envp);
		close_fd(0);
	}
	else
		display_error("Wrong number of arguments.\n");
	return (0);
}
