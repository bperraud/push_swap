/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 02:46:05 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/20 02:46:05 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// descend dans stack_a, remonte dans stack_b
t_best	best_down_up(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	int		op;
	int		move_end_a;
	int		move_end_b;

	move_end_a = -1;
	s.min_op = INT_MAX;
	while (move_end_a++ <= lstsize(stack_a))
	{
		move_end_b = lstsize(stack_b) - find_elem_max(stack_b, stack_a->cont);
		op = move_end_b + move_end_a;
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

t_best	best_up_down(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	t_list	*last;
	int		op;
	int		move_end_a;
	int		move_end_b;

	move_end_a = 0 ;
	s.min_op = INT_MAX;
	last = lstlast(stack_a);
	while (last)
	{
		move_end_a++;
		move_end_b = find_elem_max(stack_b, last->cont);
		op = move_end_b + move_end_a;
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

void	move_down_up(t_list **stack_a, t_list **stack_b, t_best best)
{
	while (best.move_end_a--)
		action(stack_a, stack_b, "ra");
	while (best.move_end_b--)
		action(stack_a, stack_b, "rrb");
}

void	move_up_down(t_list **stack_a, t_list **stack_b, t_best best)
{
	while (best.move_end_a--)
		action(stack_a, stack_b, "rra");
	while (best.move_end_b--)
		action(stack_a, stack_b, "rb");
}

void	find_best_op(t_list **stack_a, t_list **stack_b, t_op op)
{
	int	min_op;

	min_op = t_best_min(op.top, op.bot, op.down_up, op.up_down);
	if (op.top.min_op == min_op)
		move_top_opti(stack_a, stack_b, op.top);
	else if (op.bot.min_op == min_op)
		move_bot_opti(stack_a, stack_b, op.bot);
	else if (op.down_up.min_op == min_op)
		move_down_up(stack_a, stack_b, op.down_up);
	else if (op.up_down.min_op == min_op)
		move_up_down(stack_a, stack_b, op.up_down);
}
