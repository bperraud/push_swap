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

t_best	best_down_up(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	int		operation;
	int		move_to_end_a;
	int		move_to_end_b;

	move_to_end_a = -1;
	s.min_operation = INT_MAX;
	while (move_to_end_a++ <= lstsize(stack_a))
	{
		move_to_end_b = lstsize(stack_a) - find_elem_max(stack_b, (stack_a)->content);
		operation = move_to_end_b + move_to_end_a;
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

t_best	best_up_down(t_list *stack_a, t_list *stack_b)
{
	t_best	s;
	t_list	*last;
	int		operation;
	int		move_to_end_a;
	int		move_to_end_b;

	s.move_to_end_a = 0 ;		// peut être opti
	s.min_operation = INT_MAX;
	last = lstlast(stack_a);
	while (last)
	{
		move_to_end_a++;
		move_to_end_b = find_elem_max(stack_b, last->content);
		operation = move_to_end_b + move_to_end_a;
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
