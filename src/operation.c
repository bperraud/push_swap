/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:04:36 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/27 17:04:36 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the top two numbers
void	swap(t_list *lst)
{
	int		temp;
	t_list	*list;

	if (lst->is_empty)
		return ;
	list = lst->next;
	temp = list->content;
	list->content = lst->content;
	lst->content = temp;
}

//push top of stack a to b
void	push(t_list **a, t_list **b)
{
	if ((*a)->is_empty)
		return ;
	lstadd_front(b, lstnew((*a)->content));
	lstdel_front(a);
}

void	r_rotate(t_list **lst)
{
	t_list	*last;

	if ((*lst)->is_empty)
		return ;
	last = lstlast(*lst);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *lst;
	(*lst)->previous = last;
	*lst = last;
}

void	rotate(t_list **lst)
{
	t_list	*last;
	t_list	*save;

	if ((*lst)->is_empty)
		return ;
	save = (*lst)->next;
	last = lstlast(*lst);
	(*lst)->next->previous = NULL;
	(*lst)->previous = last;
	(*lst)->next = NULL;
	last->next = *lst;
	*lst = save;
}
