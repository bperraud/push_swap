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

t_best	best_op_top_half(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	int		op;
	int		move_end_a;
	int		move_end_b;

	move_end_a = -1;
	s.min_op = INT_MAX;
	while (move_end_a++ <= lstsize(stack_a) / 2 + 1)
	{
		move_end_b = find_elem_max(stack_b, (stack_a)->cont);
		op = max(move_end_b, move_end_a);
		if (op < s.min_op)
		{
			s.min_op = op;
			s.move_end_b = move_end_b;
			s.move_end_a = move_end_a;
		}
		stack_a = (stack_a)->next;
	}
	return (s);
}

t_best	best_op_bot_half(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	t_list	*last;
	int		op;
	int		move_end_a;
	int		move_end_b;

	move_end_a = 0;
	s.min_op = INT_MAX;
	last = lstlast(stack_a);
	while (move_end_a++ < (lstsize(stack_a) / 2))
	{
		move_end_b = lstsize(stack_b)
			- find_elem_max(stack_b, last->cont);
		op = max(move_end_b, move_end_a);
		if (op < s.min_op)
		{
			s.min_op = op;
			s.move_end_b = move_end_b;
			s.move_end_a = move_end_a;
		}
		last = last->previous;
	}
	return (s);
}

void	move_top_opti(t_list **stack_a, t_list **stack_b, t_best best)
{
	int	rrotate;
	int	rotate;

	if (best.move_end_a && best.move_end_b)
	{
		rrotate = min(best.move_end_a, best.move_end_b);
		while (rrotate--)
			action(stack_a, stack_b, "rr");
	}
	if (best.move_end_a > best.move_end_b)
	{
		rotate = best.move_end_a - best.move_end_b;
		while (rotate--)
			action(stack_a, stack_b, "ra");
	}
	else
	{
		rotate = best.move_end_b - best.move_end_a;
		while (rotate--)
			action(stack_a, stack_b, "rb");
	}
}

void	move_bot_opti(t_list **stack_a, t_list **stack_b, t_best best)
{
	int	rrotate;
	int	rotate;

	if (best.move_end_a && best.move_end_b)
	{
		rrotate = min(best.move_end_a, best.move_end_b);
		while (rrotate--)
			action(stack_a, stack_b, "rrr");
	}
	if (best.move_end_a > best.move_end_b)
	{
		rotate = best.move_end_a - best.move_end_b;
		while (rotate--)
			action(stack_a, stack_b, "rra");
	}
	else
	{
		rotate = best.move_end_b - best.move_end_a;
		while (rotate--)
			action(stack_a, stack_b, "rrb");
	}
}

int	t_best_min(t_best a, t_best b, t_best c, t_best d)
{
	int	min;

	min = INT_MAX;
	if (a.min_op < min)
		min = a.min_op;
	if (b.min_op < min)
		min = b.min_op;
	if (c.min_op < min)
		min = c.min_op;
	if (d.min_op < min)
		min = d.min_op;
	return (min);
}
