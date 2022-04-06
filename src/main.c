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
	t_list *stack_a;
	t_list *stack_b;

	if (argc < 2)
		return (0);
	stack_a = lst_init(argc, argv);
	/*
	if (is_sorted(stack_a))
		return (0);
		*/

	printf("has dupplicate : %i\n", has_dupplicate(stack_a));
	printf("is_sorted : %i\n", is_sorted(stack_a));	

	push_swap(stack_a);
	return (0);
}


int	main2()
{
	t_list *stack_a;
	t_list *stack_b;
	//stack_b = lst_init(argc, argv);


	//lstadd_front(&lst, lstnew(-1));
	lstadd_front(&stack_a, lstnew(-1));
	lst_print(stack_a);

	printf("swap : ---\n");
	swap(stack_a);
	lst_print(stack_a);
	printf("size : %i\n", lstsize(stack_a));

	printf("rotate : ---\n");
	rotate(&stack_a);
	lst_print(stack_a);
	printf("size : %i\n", lstsize(stack_a));

	printf("push a to b : ---\n");
	push(&stack_a, &stack_b);

	lst_print(stack_a);
	printf("------\n");
	lst_print(stack_b);
	printf("size : %i\n", lstsize(stack_a));

	lstclear(&stack_a);
}


void	exit_error()
{
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}
