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
		move_to_top_b(stack_b, find_elem(*stack_b, (*stack_a)->content)); 
		action(stack_a, stack_b, "pb");
		move_to_top_b(stack_b, find_elem(*stack_b, (*stack_a)->content)); 
		action(stack_a, stack_b, "pb");
		move_to_top_b(stack_b, find_elem(*stack_b, lstmax(*stack_b) + 1));
		size = lstsize(*stack_b);
		while (size--)
			action(stack_a, stack_b, "pa");
	}
}

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
			move_to_top_2(stack_a, stack_b, best);
		}
		else
		{
			best = bot;
			move_to_bot_2(stack_a, stack_b, best);
		}
		action(stack_a, stack_b, "pb");
	}
}

//return position of the greatest lower value of compare
int	find_elem(t_list *stack_b, int compare)
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

// rotate or shift stack_b, while content not in position place
void	move_to_top_b(t_list **stack_b, int position)
{
	int	size;

	if (position == 0)
		return ;
	size = lstsize(*stack_b);
	if (position <= size/2)
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

void	move_to_top_a(t_list **stack_a, int position)
{
	int	size;

	if (position == 0)
		return ;
	size = lstsize(*stack_a);
	if (position <= size/2)
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
	else if (a->content < a->next->next->content && a->content < a->next->content)
	{
		action(stack_a, NULL, "sa");
		action(stack_a, NULL, "ra");
	}
	else if (a->content < a->next->content && a->content > a->next->next->content)
		action(stack_a, NULL, "rra");
}

//return position of the lower greatest value of compare
int	find_elem_2(t_list *stack_b, int compare)
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

void	sort_5(t_list **a, t_list **b)
{
	action(a, b, "pb");
	action(a, b, "pb");

	if (!is_sorted(*a))
		sort_3(a);
	move_to_top_a(a, find_elem_2(*a, (*b)->content));
	action(a, b, "pa");
	move_to_top_a(a, find_elem_2(*a, (*b)->content));
	action(a, b, "pa");
	move_to_top_a(a, find_elem(*a, lstmin(*a) + 1));
}
