/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:50:55 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/19 16:01:33 by lboulatr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	ft_is_charset(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static void	free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

static int	count_rows(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
		{
			count++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*ft_str(const char *s, char c, int *index)
{
	int		i;
	int		start;
	char	*str;

	i = 0;
	start = 0;
	while (ft_is_charset(s[*index], c) && s[*index])
		(*index)++;
	while (s[*index + start] && (ft_is_charset(s[*index + start], c) == 0))
		start++;
	str = malloc(sizeof(char) * (start + 1));
	if (!str)
		return (NULL);
	while (i < start)
	{
		str[i] = s[*index];
		(*index)++;
		i++;
	}
	str[start] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		index;
	int		rows;
	char	**array;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	else
	{
		rows = count_rows(s, c);
		array = (char **)malloc((rows + 1) * sizeof(char *));
		if (!array)
			return (NULL);
		while (i < rows)
		{
			array[i] = ft_str(s, c, &index);
			if (!array[i])
				return (free_str_array(array), NULL);
			i++;
		}
		return (array[i] = 0, array);
	}
}
