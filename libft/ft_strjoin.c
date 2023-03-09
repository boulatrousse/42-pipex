/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:51:49 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 14:09:33 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		j;
	int		k;
	char	*dest;

	j = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (dest == NULL)
		return (0);
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	while (s2[k])
		dest[j++] = s2[k++];
	dest[j] = '\0';
	return (dest);
}
