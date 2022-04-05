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

	if (!*alst)
	{
		*alst = new;
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
}

t_list	*lstlast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->next = NULL;
	list->previous = NULL;
	list->content = content;
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


void	lstiter(t_list *lst, void (*f)(void*))
{
	if (lst && f)
	{
		while (lst->next)
		{
			(f)(lst->content);
			lst = lst->next;
		}
		(f)(lst->content);
	}
}


void	lstclear(t_list **lst)
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
	}
	*lst = NULL;
}


void	lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(*del)(lst->content);
		free(lst);
	}
}


t_list	*lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*plist;
	t_list	*elem;

	plist = NULL;
	if (lst && f)
	{
		while (lst)
		{
			elem = lstnew((*f)(lst->content));
			if (elem)
			{
				lstadd_back(&plist, elem);
				lst = lst->next;
			}
			else
			{
				lstclear(&plist);
				return (NULL);
			}
		}
		return (plist);
	}
	return (NULL);
}
