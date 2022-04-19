/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:13:32 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/15 15:13:32 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_best	best_operation_top_half(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	int		operation;
	int		move_to_end_a;
	int		move_to_end_b;

	move_to_end_a = -1;
	move_to_end_b = 0;
	s.min_operation = INT_MAX;
	while (move_to_end_a++ <= lstsize(stack_a) / 2 + 1)
	{
		move_to_end_b = find_elem_max(stack_b, (stack_a)->content);
		operation = max(move_to_end_b, move_to_end_a);
		if (operation < s.min_operation)
		{
			s.min_operation = operation;
			s.move_to_end_b = move_to_end_b;
			s.move_to_end_a = move_to_end_a;
		}
		stack_a = (stack_a)->next;
	}
	return (s);
}

t_best	best_operation_bot_half(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	t_list	*last;
	int		operation;
	int		move_to_end_a;
	int		move_to_end_b;

	s.move_to_end_a = 0;
	s.move_to_end_b = 0;
	s.min_operation = INT_MAX;
	last = lstlast(stack_a);
	while (move_to_end_a++ < lstsize(stack_a) / 2)
	{
		move_to_end_b = lstsize(stack_b)
			- find_elem_max(stack_b, last->content);
		operation = max(move_to_end_b, move_to_end_a);
		if (operation < s.min_operation)
		{
			s.min_operation = operation;
			s.move_to_end_b = move_to_end_b;
			s.move_to_end_a = move_to_end_a;
		}
		last = last->previous;
	}
	return (s);
}

void	move_to_top_opti(t_list **stack_a, t_list **stack_b, t_best best)
{
	int	rrotate;
	int	rotate;

	if (best.move_to_end_a && best.move_to_end_b)
	{
		rrotate = min(best.move_to_end_a, best.move_to_end_b);
		while (rrotate--)
			action(stack_a, stack_b, "rr");
	}
	if (best.move_to_end_a > best.move_to_end_b)
	{
		rotate = best.move_to_end_a - best.move_to_end_b;
		while (rotate--)
			action(stack_a, stack_b, "ra");
	}
	else
	{
		rotate = best.move_to_end_b - best.move_to_end_a;
		while (rotate--)
			action(stack_a, stack_b, "rb");
	}
}

void	move_to_bot_opti(t_list **stack_a, t_list **stack_b, t_best best)
{
	int	rrotate;
	int	rotate;

	if (best.move_to_end_a && best.move_to_end_b)
	{
		rrotate = min(best.move_to_end_a, best.move_to_end_b);
		while (rrotate--)
			action(stack_a, stack_b, "rrr");
	}
	if (best.move_to_end_a > best.move_to_end_b)
	{
		rotate = best.move_to_end_a - best.move_to_end_b;
		while (rotate--)
			action(stack_a, stack_b, "rra");
	}
	else
	{
		rotate = best.move_to_end_b - best.move_to_end_a;
		while (rotate--)
			action(stack_a, stack_b, "rrb");
	}
}
