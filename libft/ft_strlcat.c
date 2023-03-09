/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:03:07 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 13:59:08 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	int		i;
	int		j;

	if (size == 0)
		return (ft_strlen(src));
	size_dest = ft_strlen(dest);
	i = 0;
	if (size < size_dest)
		return (size + ft_strlen(src));
	while (dest[i] && size > 0)
	{
		i++;
		size--;
	}
	j = 0;
	while (src[j] && size > 1)
	{
		dest[i + j] = src[j];
		size--;
		j++;
	}
	if (size > 0)
		dest[i + j] = '\0';
	return (size_dest + ft_strlen(src));
}
