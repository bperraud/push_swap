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

t_list	*lst_init2(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	lst = lstnew(atoi_lst(argv[1], lst) + 1);
	i = 1;
	while (i++ < argc - 1)
		lstadd_back(&lst, lstnew(atoi_lst(argv[i], lst) + 1));
	return (lst);
}


int	main(int argc, char **argv)
{	
	t_list *stack_a;
	t_list *stack_b;

	//t_stacks *stacks;
	//stacks = malloc(sizeof(t_stacks));
	//stack_b = malloc(sizeof(t_list));

	if (argc < 2)
		return (0);

	stack_b = malloc(sizeof(t_list));
	stack_b->is_empty = 1;
	stack_a = lst_init(argc, argv);

	//stack_b = lst_init2(argc, argv);

	printf("a : \n");
	lst_print(stack_a);
	printf("b : \n");
	lst_print(stack_b);

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

	printf("------\n");
	push_swap(&stack_a, &stack_b);
	lst_print(stack_a);
	printf("------\n");
	lst_print(stack_b);

	lstclear(&stack_a);
	lstclear(&stack_b);
	

	return (0);
}
