/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:42:37 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 13:16:26 by lboulatr         ###   ########.fr       */
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
	}
	else
		display_error("Wrong number of arguments.\n");
	close_fd(0);
	return (0);
}
