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

#include "push_swap.h"

t_list	*lst_init(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	lst->is_empty = 1;
	if (!ft_strlen(argv[1]))
		exit_error(lst);
	lstadd_back(&lst, lstnew(atoi_lst(argv[1], lst)));
	i = 1;
	while (i++ < argc - 1)
	{
		if (!ft_strlen(argv[i]))
			exit_error(lst);
		lstadd_back(&lst, lstnew(atoi_lst(argv[i], lst)));
	}
	return (lst);
}

void	lstdel_front(t_list **lst)
{
	if (lstsize(*lst) == 1)
	{
		(*lst)->is_empty = 1;
		free((*lst)->previous);
		free((*lst)->next);
		return ;
	}
	*lst = (*lst)->next;
	free((*lst)->previous);
	(*lst)->previous = NULL;
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
}
