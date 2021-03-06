/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:17 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/27 17:40:17 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_dupplicate(t_list *lst)
{
	t_list	*comp;

	while (lst->next)
	{
		comp = lst;
		while (comp->next)
		{
			if (comp->next->cont == lst->cont)
				return (1);
			comp = comp->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if (lst->cont > lst->next->cont)
			return (0);
		lst = lst->next;
	}
	return (1);
}
