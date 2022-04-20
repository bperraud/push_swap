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
	t_best	top;
	t_best	bot;
	t_best	down_up;
	t_best	up_down;

	t_best	best;

	size -= 2;
	while (size--)
	{
		top = best_operation_top_half(*stack_a, *stack_b);
		bot = best_operation_bot_half(*stack_a, *stack_b);

		down_up = best_down_up(*stack_a, *stack_b);
		up_down = best_up_down(*stack_a, *stack_b);

		/*
		printf("top : %i\n", top.min_operation);
		printf("bot : %i\n", bot.min_operation);
		*/

		if (top.min_operation < bot.min_operation)
		{
			best = top;
			move_to_top_opti(stack_a, stack_b, best);
		}
		else
		{
			best = bot;
			//move_to_top_opti(stack_a, stack_b, best);
			move_to_bot_opti(stack_a, stack_b, best);		// fonctionne ?
		}

		if (up_down.min_operation < top.min_operation && up_down.min_operation < bot.min_operation )
		{
			//printf("belle opti !\n");
		}


		action(stack_a, stack_b, "pb");
	}
}

void	sort_3(t_list **stack_a)
{
	t_list	*a;

	a = *stack_a;
	if (a->content < a->next->next->content && a->content > a->next->content)
		action(stack_a, NULL, "sa");
	else if (a->content > a->next->content
		&& a->next->content > a->next->next->content)
	{
		action(stack_a, NULL, "sa");
		action(stack_a, NULL, "rra");
	}
	else if (a->next->next->content > a->next->content
		&& a->content > a->next->next->content)
		action(stack_a, NULL, "ra");
	else if (a->content < a->next->next->content
		&& a->content < a->next->content)
	{
		action(stack_a, NULL, "sa");
		action(stack_a, NULL, "ra");
	}
	else if (a->content < a->next->content
		&& a->content > a->next->next->content)
		action(stack_a, NULL, "rra");
}

void	sort_4(t_list **a, t_list **b)
{
	action(a, b, "pb");
	if (!is_sorted(*a))
		sort_3(a);
	move_to_top_a(a, find_elem_min(*a, (*b)->content));
	action(a, b, "pa");
	move_to_top_a(a, find_elem_max(*a, lstmin(*a) + 1));
}

void	sort_5(t_list **a, t_list **b)
{
	action(a, b, "pb");
	action(a, b, "pb");
	if (!is_sorted(*a))
		sort_3(a);
	move_to_top_a(a, find_elem_min(*a, (*b)->content));
	action(a, b, "pa");
	move_to_top_a(a, find_elem_min(*a, (*b)->content));
	action(a, b, "pa");
	move_to_top_a(a, find_elem_max(*a, lstmin(*a) + 1));
}
