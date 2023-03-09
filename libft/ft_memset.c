/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:44:47 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/07 17:07:52 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
	return (b);
}
