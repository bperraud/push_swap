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

#include "../include/push_swap.h"


// list trié ordre croissant : échanger les deux du haut = les deux plus petits = les deux premiers éléments
// swap the top two numbers
void	swap(t_list *lst)
{
	int		temp;
	t_list	*list;
	int		size;

	size = lst->size;
	list = lst->next;	
	temp = list->content;
	list->content = lst->content;
	lst->content = temp;
	lst->size = size;
}


//push top of stack a to b
void	push(t_list **a, t_list **b)
{
	lstadd_back(b, lstnew((*a)->content));
	lstdel_front(a);
}


//  top number in A goes to bottom of A
// interet de la liste doublement chainé sans référence à la fin de liste ? (aucun je pense)
void	rotate(t_list **lst)
{
	int		size;
	t_list	*last;

	size = (*lst)->size;
	last = lstlast(*lst);
	last->previous->next = NULL;
	last->previous = NULL;
	last->next = *lst;
	(*lst)->previous = last;
	*lst = last;
	(*lst)->size = size;
}
