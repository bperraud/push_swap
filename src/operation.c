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


// list trié ordre croissant : échanger les deux du haut = les deux plus petites = les deux premiers éléments
// swap the top two numbers
void	swap(t_list **lst)
{
	t_list	*list;
	list = (*lst)->next;	// 2e élement

	list->previous = NULL;		// devient premier élement = previous = NULL 


	lst->next = list->next;
	list->next->previous = lst;
	list->next = lst;
	
	
	//list = lst; //? 
}

void	push(t_list *a, t_list *b)
{
	t_list *temp;

	temp = 
}

//  top number in A goes to bottom of A
void	rotate(t_list **lst)
{
	t_list	*list;

	list = lst;

	list->next->previous = list;
	list->next = NULL;

	lst->next->next->previous = lst;
	lst->next->next = lst;
	lst->next = lst;
}
