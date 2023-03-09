/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:34:30 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 10:37:08 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	b;
	unsigned char	*s;

	i = 0;
	b = c;
	s = (unsigned char *)str;
	while (i < n)
	{
		if (s[i] == b)
			return (&s[i]);
		i++;
	}
	return (0);
}
