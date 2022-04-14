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
#include "../libft/libft.h"

int	main(int argc, char **argv)
{	
	t_list *stack_a;
	t_list *stack_b;

	if (argc < 2)
		return (0);

	stack_b = malloc(sizeof(t_list));
	stack_b->is_empty = 1;
	stack_a = lst_init(argc, argv);

	if (has_dupplicate(stack_a))
	{
		ft_putendl_fd("Error", 2);
		free_exit(&stack_a, &stack_b);
	}
	if (is_sorted(stack_a))
		free_exit(&stack_a, &stack_b);
	
		
	/*
	printf("swap : ---\n");
	swap(stack_a);
	lst_print(stack_a);
	printf("size : %i\n", lstsize(stack_a));

	
	printf("rotate : ---\n");
	rotate(&stack_a);
	lst_print(stack_a);
	printf("size : %i\n", lstsize(stack_a));
	

	printf("r_rotate : ---\n");
	r_rotate(&stack_a);
	lst_print(stack_a);
	printf("size : %i\n", lstsize(stack_a));


	printf("push a to b : ---\n");
	push(&stack_a, &stack_b);

	lst_print(stack_a);
	printf("------\n");
	lst_print(stack_b);
	printf("size a : %i\n", lstsize(stack_a));
	printf("size b : %i\n", lstsize(stack_b));
	*/

	/*
	printf("------\n");
	lst_print(stack_b);

	printf("pos of greatest lower of 7: %i\n", find_elem(stack_b, 7));
	move_to_top(&stack_b, find_elem(stack_b, 7));
	lst_print(stack_b);

	printf("pos of greatest lower of 5: %i\n", find_elem(stack_b, 5));
	move_to_top(&stack_b, find_elem(stack_b, 5));
	lst_print(stack_b);

	printf("pos of greatest lower of 11: %i\n", find_elem(stack_b, 11));
	move_to_top(&stack_b, find_elem(stack_b, 11));
	lst_print(stack_b);

	lst_print(stack_b);

	printf("pos of greatest lower of 7: %i\n", find_elem(stack_b, 7));
	move_to_top(&stack_b, find_elem(stack_b, 7));
	lst_print(stack_b);

	*/

	/*
	printf("pos of greatest lower of -3: %i\n", find_elem(stack_a, -3));
	move_to_top(&stack_a, find_elem(stack_a, -3));
	lst_print(stack_a);

	lst_print(stack_a);

	printf("pos of greatest lower of -6: %i\n", find_elem(stack_a, -6));
	move_to_top(&stack_a, find_elem(stack_a, -6));
	lst_print(stack_a);
	*/

	
	printf("------\n");
	push_swap(&stack_a, &stack_b);
	lst_print(stack_a);
	printf("------\n");
	lst_print(stack_b);
	
	if (is_sorted(stack_a))
		printf("sorted !");

	
	free_exit(&stack_a, &stack_b);
	return (0);
}

void	free_exit(t_list **stack_a, t_list **stack_b)
{
	lstclear(stack_a);
	lstclear(stack_b);
	exit(EXIT_SUCCESS);
}
