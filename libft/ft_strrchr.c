/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:38:34 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/14 15:29:12 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		x;
	char	b;
	char	*s;

	x = ft_strlen(str) - 1;
	b = c;
	s = (char *)str;
	if (!s || (str[x + 1] == '\0' && b == '\0'))
		return (&s[x + 1]);
	while (x >= 0)
	{
		if (s[x] == b)
			return (&s[x]);
		else
			x--;
	}
	return (0);
}
