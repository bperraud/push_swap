/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 17:25:00 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/06 17:25:00 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		size;

	size = lstsize(*stack_a);
	if (size <= 5)
		short_sort(stack_a, stack_b, size);
	else
	{
		sort_until_2(stack_a, stack_b, size);
		move_to_top_b(stack_b, find_elem_max(*stack_b, (*stack_a)->content));
		action(stack_a, stack_b, "pb");
		move_to_top_b(stack_b, find_elem_max(*stack_b, (*stack_a)->content));
		action(stack_a, stack_b, "pb");
		move_to_top_b(stack_b, find_elem_max(*stack_b, lstmax(*stack_b) + 1));
		size = lstsize(*stack_b);
		while (size--)
			action(stack_a, stack_b, "pa");
	}
}

//return position of the greatest lower value of compare
int	find_elem_max(t_list *stack_b, int compare)
{
	int		max;
	int		position;
	int		i;
	int		bool;
	t_list	*start;

	start = stack_b;
	bool = 1;
	position = 0;
	i = 0;
	max = INT_MIN;
	while (stack_b)
	{
		if (stack_b->content > max && stack_b->content < compare)
		{
			bool = 0;
			max = stack_b->content;
			position = i;
		}
		i += 1;
		stack_b = stack_b->next;
	}
	if (bool)
		return (lstmax_position(start));
	return (position);
}

void	move_to_top_a(t_list **stack_a, int position)
{
	int	size;

	if (position == 0)
		return ;
	size = lstsize(*stack_a);
	if (position <= size / 2)
	{
		while (position--)
			action(stack_a, stack_a, "ra");
	}
	else
	{
		size -= position;
		while (size--)
			action(stack_a, stack_a, "rra");
	}
}

// rotate or shift stack_b, while content not in position place
void	move_to_top_b(t_list **stack_b, int position)
{
	int	size;

	if (position == 0)
		return ;
	size = lstsize(*stack_b);
	if (position <= size / 2)
	{
		while (position--)
			action(stack_b, stack_b, "rb");
	}
	else
	{
		size -= position;
		while (size--)
			action(stack_b, stack_b, "rrb");
	}
}

//return position of the lower greatest value of compare
int	find_elem_min(t_list *stack_b, int compare)
{
	int		min;
	int		position;
	int		i;
	int		bool;
	t_list	*start;

	start = stack_b;
	bool = 1;
	position = 0;
	i = 0;
	min = INT_MAX;
	while (stack_b)
	{
		if (stack_b->content < min && stack_b->content > compare)
		{
			bool = 0;
			min = stack_b->content;
			position = i;
		}
		i += 1;
		stack_b = stack_b->next;
	}
	if (bool)
		return (lstmin_position(start));
	return (position);
}
