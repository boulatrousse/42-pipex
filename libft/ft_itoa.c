/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 15:06:30 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 15:38:31 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

static int	count(long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*is_pos(long int n, int i)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = i - 1;
	str = malloc(i * sizeof(char));
	if (str == NULL)
		return (0);
	while (x < y)
	{
		str[y - 1] = ((n % 10) + 48);
		n /= 10;
		y--;
	}
	str[i - 1] = '\0';
	return (str);
}

static char	*is_neg(long int n, int i)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	y = i - 1;
	n *= -1;
	str = malloc(i * sizeof(char));
	if (str == NULL)
		return (0);
	if (n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	while (x < y)
	{
		str[y - 1] = ((n % 10) + 48);
		n /= 10;
		y--;
	}
	str[0] = '-';
	str[i - 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	x;
	char		*str;

	i = count(n) + 1;
	x = n;
	if (x >= 0)
		str = is_pos(x, i);
	else
		str = is_neg(x, i);
	return (str);
}
