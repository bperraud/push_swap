/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 16:39:27 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/27 16:39:27 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{	
	t_list *lst;

	lst = lst_init(argc, argv, lst);

	//lstadd_front(&lst, lstnew(-1));
	lstadd_front(&lst, lstnew(-1));
	lst_print(lst);

	printf("swap : ---\n");
	swap(lst);
	lst_print(lst);
	printf("size : %i\n", lstsize(lst));

	printf("rotate : ---\n");
	rotate(&lst);
	lst_print(lst);
	printf("size : %i\n", lstsize(lst));

	lstclear(&lst);
	return (0);
}
