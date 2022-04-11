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

t_list	*lst_init(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	lst = lstnew(atoi_lst(argv[1], lst));
	i = 1;
	while (i++ < argc - 1)
		lstadd_back(&lst, lstnew(atoi_lst(argv[i], lst)));
	return (lst);
}

void	lst_print(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			printf("%i\n", lst->content);
			lst = lst->next;
		}
		printf("%i\n", lst->content);
	}
}

void	lstdel_front(t_list **lst)
{
	t_list	*list;

	*lst = (*lst)->next;
	free((*lst)->previous);
	(*lst)->previous = NULL;
	(*lst)->size -= 1;
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

