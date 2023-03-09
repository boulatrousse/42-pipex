/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 08:13:31 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/14 14:14:16 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = ft_strlen(s1) + 1;
	s2 = malloc(i * sizeof(char));
	if (s2 == NULL)
		return (0);
	ft_memcpy(s2, s1, i);
	s2[i - 1] = '\0';
	return (s2);
}
