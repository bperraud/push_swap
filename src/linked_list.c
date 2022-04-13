/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:00:18 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/05 19:00:18 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if ((*alst)->is_empty == 1)
	{
		free(*alst);
		*alst = new;
		(*alst)->is_empty = 0;
		return ;
	}
	list = *alst;
	while (list->next)
		list = list->next;
	list->next = new;
	new->previous = list;
}

void	lstadd_front(t_list **alst, t_list *new)
{
	if ((*alst)->is_empty == 1)
	{
		free(*alst);
		*alst = new;
		(*alst)->is_empty = 0;
		return ;
	}
	if (new)
	{
		while (new->next)
			new = new->next;
		new->next = *alst;
		(*alst)->previous = new;
		*alst = new;
	}
}

t_list	*lstlast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*lstnew(int content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->previous = NULL;
	list->content = content;
	list->is_empty = 0;
	return (list);
}

int	lstsize(t_list *lst)
{
	int	size;

	if (lst)
		size = 1;
	else
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		size += 1;
	}
	return (size);
}
