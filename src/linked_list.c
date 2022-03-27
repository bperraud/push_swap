/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_chaine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:46:02 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/27 18:46:02 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


void	list_printf(t_list *lst)
{
	while (lst->next)
	{
		printf("%i\n", lst->content); 
		lst = lst->next;
	}
	printf("%i\n", lst->content); 
}

void	ft_lstadd_back(t_list **alst, t_list *new)
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


void	ft_lstadd_front(t_list **alst, t_list *new)
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

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstnew(void *content)
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


int	ft_lstsize(t_list *lst)
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
