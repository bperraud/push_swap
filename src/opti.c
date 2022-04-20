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
	int		operation;
	int		move_to_end_a;
	int		move_to_end_b;

	move_to_end_a = -1;
	s.min_op = INT_MAX;
	while (move_to_end_a++ <= lstsize(stack_a))
	{
		move_to_end_b = lstsize(stack_b) - find_elem_max(stack_b, (stack_a)->content) ;
		operation = move_to_end_b + move_to_end_a;
		if (operation < s.min_op)
		{
			s.min_op = operation;
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

	move_to_end_a = 0 ;		// peut être opti
	s.min_op = INT_MAX;
	last = lstlast(stack_a);
	while (last)
	{
		move_to_end_a++;
		move_to_end_b = find_elem_max(stack_b, last->content);
		operation = move_to_end_b + move_to_end_a;
		if (operation < s.min_op)
		{
			s.min_op = operation;
			s.move_to_end_b = move_to_end_b;
			s.move_to_end_a = move_to_end_a;
		}
		last = last->previous;
	}
	return (s);
}

void	lst_print(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			printf("%i\n", lst->content);
			lst = lst->next;
		}
		printf("%i\n", lst->content);
	}
}

void	move_down_up(t_list **stack_a, t_list **stack_b, t_best best)
{
	while(best.move_to_end_a--)
		action(stack_a, stack_b, "ra");
	while(best.move_to_end_b--)
		action(stack_a, stack_b, "rrb");
}

void	move_up_down(t_list **stack_a, t_list **stack_b, t_best best)
{
	while(best.move_to_end_a--)
		action(stack_a, stack_b, "rra");
	while(best.move_to_end_b--)
		action(stack_a, stack_b, "rb");
}


void	find_best_operation(t_list **stack_a, t_list **stack_b, t_all_best all_best)
{
	int	min_op;

	min_op = t_best_min(all_best.top, all_best.bot, all_best.down_up, all_best.up_down);
	if (all_best.top.min_op == min_op)
		move_to_top_opti(stack_a, stack_b, all_best.top);
	else if (all_best.bot.min_op == min_op)
		move_to_bot_opti(stack_a, stack_b, all_best.bot);
	else if (all_best.down_up.min_op == min_op)
		move_down_up(stack_a, stack_b, all_best.down_up);
	else if (all_best.up_down.min_op == min_op)
		move_up_down(stack_a, stack_b, all_best.up_down);
}
