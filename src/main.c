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
	//t_list *stack_a;
	//t_list *stack_b;

	t_stacks *stacks;

	if (argc < 2)
		return (0);

	stacks = malloc(sizeof(t_stacks));
	stacks->a = lst_init(argc, argv);
	stacks->b = malloc(sizeof(t_list));

	lst_print(stacks->a);
	

	if (has_dupplicate(stacks->a))
	{
		printf("has_dupplicate");
		ft_putendl_fd("Error", 2);
		return (0);
	}

	if (is_sorted(stacks->a) )
	{
		printf("sorted");
		return (0);
	}
	
	
	printf("swap : ---\n");
	swap(stacks->a);
	lst_print(stacks->a);
	printf("size : %i\n", stacks->a->size);

	printf("rotate : ---\n");
	rotate(&stacks->a);
	lst_print(stacks->a);
	printf("size : %i\n", stacks->a->size);

	printf("push a to b : ---\n");
	push(&stacks->a, &stacks->b);

	lst_print(stacks->a);
	printf("------\n");
	lst_print(stacks->b);
	printf("size a : %i\n", stacks->a->size);
	printf("size b : %i\n", stacks->b->size);

	lstclear(&stacks->a);
	lstclear(&stacks->b);

	free(stacks);

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


	printf("rotate : ---\n");
	rotate(&stack_a);
	lst_print(stack_a);


	printf("push a to b : ---\n");
	push(&stack_a, &stack_b);

	lst_print(stack_a);
	printf("------\n");
	lst_print(stack_b);


	lstclear(&stack_a);
}
