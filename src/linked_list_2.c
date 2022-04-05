/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:00:31 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/05 19:00:31 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	lst_print(t_list *lst)
{
	while (lst->next)
	{
		printf("%i\n", lst->content);
		lst = lst->next;
	}
	printf("%i\n", lst->content);
}

void	lstdel_front(t_list *lst)
{
	t_list	*list;

	lst = lst->next;
	lst->previous = NULL;
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
