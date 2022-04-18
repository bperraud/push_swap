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

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	short_sort(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
		action(stack_a, stack_b, "sa");
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		return ;
	else if (size == 5)
		sort_5(stack_a, stack_b);
}

void	sort_until_2(t_list **stack_a, t_list **stack_b, int size)
{
	t_best	top;
	t_best	bot;
	t_best	best;

	size -= 2;
	while (size--)
	{
		top = best_operation_top_half(*stack_a, *stack_b);
		bot = best_operation_bot_half(*stack_a, *stack_b);
		if (top.min_operation < bot.min_operation)
		{
			best = top;
			move_to_top_opti(stack_a, stack_b, best);
		}
		else
		{
			best = bot;
			move_to_top_opti(stack_a, stack_b, best);
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

void	action(t_list **stack_a, t_list **stack_b, char *action)
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
}
