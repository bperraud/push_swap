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
//#include "../libft/get_next_line_bonus.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{	
	t_list *stack_a;
	t_list *stack_b;
	
	if (argc < 2)
		return (0);
		
	stack_a = lst_init(argc, argv);
	stack_b = malloc(sizeof(t_list));
	lst_print(stack_a);
	
	if (has_dupplicate(stack_a))
	{
		printf("has_dupplicate");
		ft_putendl_fd("Error", 2);
		return (0);
	}

	if (is_sorted(stack_a) )
	{
		printf("sorted");
		return (0);
	}
	
	/*
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

	printf("has dupplicate : %i\n", has_dupplicate(stack_a));
	printf("is_sorted : %i\n", is_sorted(stack_a));
	*/
	//push_swap(stack_a, stack_b);

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
