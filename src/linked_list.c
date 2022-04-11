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

	if (!(*alst)->size)		// pas oublier l'initialisation
	{
		*alst = new;
		return ;
	}
	list = *alst;
	while (list->next)
		list = list->next;
	list->next = new;
	new->previous = list;
	(*alst)->size += 1;
}

void	lstadd_front(t_list **alst, t_list *new)
{
	int	size;

	size = (*alst)->size;
	if (!*alst)
	{
		*alst = new;
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
	(*alst)->size = (*alst)->size + 1;
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
	list->size = 1;
	return (list);
}

/*
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
*/
