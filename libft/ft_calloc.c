/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 07:54:53 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 09:02:28 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else if (nmemb == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	else
	{
		array = malloc(nmemb * size);
		if (array == NULL)
			return (NULL);
		ft_bzero((unsigned char *)array, (nmemb * size));
		return (array);
	}
}
