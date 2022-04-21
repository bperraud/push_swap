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

void	action(t_list **stack_a, t_list **stack_b, char *action)
{
	ft_putendl_fd(action, 1);
	if (!ft_strcmp(action, "sa") || !ft_strcmp(action, "ss"))
		swap(*stack_a);
	if (!ft_strcmp(action, "sb") || !ft_strcmp(action, "ss"))
		swap(*stack_b);
	if (!ft_strcmp(action, "pa"))
		push(stack_b, stack_a);
	if (!ft_strcmp(action, "pb"))
		push(stack_a, stack_b);
	if (!ft_strcmp(action, "rra") || !ft_strcmp(action, "rrr"))
		r_rotate(stack_a);
	if (!ft_strcmp(action, "rrb") || !ft_strcmp(action, "rrr"))
		r_rotate(stack_b);
	if (!ft_strcmp(action, "ra") || !ft_strcmp(action, "rr"))
		rotate(stack_a);
	if (!ft_strcmp(action, "rb") || !ft_strcmp(action, "rr"))
		rotate(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = lst_init(argc, argv);
	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		free_exit(&stack_a, NULL);
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
