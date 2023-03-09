/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:08:22 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 08:43:11 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	ft_is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_front(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_is_set(s1[i], set) == 1)
		i++;
	return (i);
}

static int	ft_back(char const *s1, char const *set)
{
	int	i;
	int	x;

	i = 0;
	x = ft_strlen(s1) - 1;
	while (x >= 0 && ft_is_set(s1[x], set) == 1)
	{
		i++;
		x--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front;
	int		back;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	front = ft_front(s1, set);
	back = ft_back(s1, set);
	if (front == (int)ft_strlen(s1))
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = ft_substr(s1, front, ft_strlen(s1) - front - back);
	if (!str)
		return (NULL);
	return (str);
}
