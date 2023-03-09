/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:46:33 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 12:51:20 by lboulatr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*end;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	end = ft_lstlast(*lst);
	end->next = new;
}
