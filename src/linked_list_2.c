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

