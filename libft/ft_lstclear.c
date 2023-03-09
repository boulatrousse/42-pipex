/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:48:37 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/17 12:54:26 by lboulatr         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		while ((*lst) != NULL)
		{
			tmp = (*lst)->next;
			del((void *)((*lst)->content));
			free(*lst);
			(*lst) = tmp;
		}
	}
	else
		return ;
}
