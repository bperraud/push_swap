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
	int	i;
	int array[] = {5, 3, 4, 1};
	
	t_list *lst;

	lst = lst_init(argc, argv, lst);
	//lst = ft_lstnew(1);

	lstadd_front(&lst, lstnew(-1));
	lst_print(lst);

	printf("---\n");
	//lstdelete_front(&lst);

	lst_print(lst);

	lstclear(&lst);
	return (0);
}
