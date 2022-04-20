/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:23:52 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/18 02:23:52 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	short_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		action(stack_a, stack_b, "sa");
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

void	sort_until_2(t_list **stack_a, t_list **stack_b, int size)
{
	t_op	op;

	size -= 2;
	while (size--)
	{
		op.top = best_op_top_half(*stack_a, *stack_b);
		op.bot = best_op_bot_half(*stack_a, *stack_b);
		op.down_up = best_down_up(*stack_a, *stack_b);
		op.up_down = best_up_down(*stack_a, *stack_b);
		find_best_op(stack_a, stack_b, op);
		action(stack_a, stack_b, "pb");
	}
}

void	sort_3(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	if (a->cont < a->next->next->cont && a->cont > a->next->cont)
		action(stack_a, NULL, "sa");
	else if (a->cont > a->next->cont
		&& a->next->cont > a->next->next->cont)
	{
		action(stack_a, NULL, "sa");
		action(stack_a, NULL, "rra");
	}
	else if (a->next->next->cont > a->next->cont
		&& a->cont > a->next->next->cont)
		action(stack_a, NULL, "ra");
	else if (a->cont < a->next->next->cont
		&& a->cont < a->next->cont)
	{
		action(stack_a, NULL, "sa");
		action(stack_a, NULL, "ra");
	}
	else if (a->cont < a->next->cont
		&& a->cont > a->next->next->cont)
		action(stack_a, NULL, "rra");
}

void	sort_4(t_list **a, t_list **b)
{
	action(a, b, "pb");
	if (!is_sorted(*a))
		sort_3(a);
	move_top_a(a, find_elem_min(*a, (*b)->cont));
	action(a, b, "pa");
	move_top_a(a, find_elem_max(*a, lstmin(*a) + 1));
}

void	sort_5(t_list **a, t_list **b)
{
	action(a, b, "pb");
	action(a, b, "pb");
	if (!is_sorted(*a))
		sort_3(a);
	move_top_a(a, find_elem_min(*a, (*b)->cont));
	action(a, b, "pa");
	move_top_a(a, find_elem_min(*a, (*b)->cont));
	action(a, b, "pa");
	move_top_a(a, find_elem_max(*a, lstmin(*a) + 1));
}
