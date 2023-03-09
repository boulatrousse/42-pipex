/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:42:40 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/09 13:03:56 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_free_tmp(char *tmp, char *tmp2)
{
	free(tmp);
	free(tmp2);
}

char	*valid_path(int i, char **envp, char *str)
{
	char	*tmp;
	char	*tmp2;
	char	**paths;

	if (access(str, F_OK) == 0)
		return (str);
	paths = path_envp(envp);
	if (!paths)
		return (NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		if (!tmp)
			return (free_array(paths), NULL);
		tmp2 = ft_strjoin(tmp, str);
		if (!tmp2)
			return (free_array(paths), free(tmp), NULL);
		if (access(tmp2, F_OK) == 0)
			return (free(tmp), free_array(paths), tmp2);
		ft_free_tmp(tmp, tmp2);
		i++;
	}
	return (free_array(paths), NULL);
}

char	**path_envp(char **envp)
{
	int		i;
	char	**path;

	i = 0;
	while (envp[i] && (ft_strnstr(envp[i], "PATH", 4) == 0))
		i++;
	if (envp[i] != NULL && ft_strnstr(envp[i], "PATH", 4) != 0)
	{
		path = ft_split(envp[i] + 5, ':');
		if (!path)
			return (NULL);
		return (path);
	}
	return (NULL);
}

char	**ft_command(char *str)
{
	char	**cmd;

	cmd = ft_split(str, ' ');
	if (!cmd)
		return (NULL);
	return (cmd);
}
