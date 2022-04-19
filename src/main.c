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

#include "push_swap.h"
#include "../libft/libft.h"

int	action(t_list **stack_a, t_list **stack_b, char *action)
{
	ft_putendl_fd(action, 1);
	if (!ft_strncmp(action, "sa", 3) || !ft_strncmp(action, "ss", 3))
		swap(*stack_a);
	if (!ft_strncmp(action, "sb", 3) || !ft_strncmp(action, "ss", 3))
		swap(*stack_b);
	if (!ft_strncmp(action, "pa", 3))
		push(stack_b, stack_a);
	if (!ft_strncmp(action, "pb", 3))
		push(stack_a, stack_b);
	if (!ft_strncmp(action, "rra", 3) || !ft_strncmp(action, "rrr", 3))
		r_rotate(stack_a);
	if (!ft_strncmp(action, "rrb", 3) || !ft_strncmp(action, "rrr", 3))
		r_rotate(stack_b);
	if (!ft_strncmp(action, "ra", 3) || !ft_strncmp(action, "rr", 3))
		rotate(stack_a);
	if (!ft_strncmp(action, "rb", 3) || !ft_strncmp(action, "rr", 3))
		rotate(stack_b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = lst_init(argc, argv);
	stack_b = malloc(sizeof(t_list));
	stack_b->is_empty = 1;
	if (has_dupplicate(stack_a))
	{
		ft_putendl_fd("Error", 2);
		free_exit(&stack_a, &stack_b);
	}
	if (is_sorted(stack_a))
		free_exit(&stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	free_exit(&stack_a, &stack_b);
	return (0);
}
