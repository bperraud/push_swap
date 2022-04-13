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
	int	size;

	size = lstsize(*stack_a);

	/*
	if (size == 2)
		ft_putendl_fd("sa", 1);
	else if (size == 3)
		three_push_swap(stack_a);
	*/

	if (size > 10)
	{
		while (lstsize(*stack_a))		// trier à l'envers dans b
		{
			//move_to_top(stack_b, stack_a->content);		// move the right element at top of b;
			//action(stack_a, stack_b, "pb");	// push from a to b
		}
		while (lstsize(*stack_b))
			//action(stack_a, stack_b, "pa");
			;
	}
}


//return position of the greatest lower value of compare
int	find_elem(t_list *stack_b, int compare)
{
	int	max;
	int	position;
	int	i;

	position = 0;
	i = 0;
	max = INT_MIN;
	while (stack_b)
	{
		if (stack_b->content > max && stack_b->content < compare)
		{
			max = stack_b->content;
			position = i;
		}
		i += 1;
		stack_b = stack_b->next;
	}
	return (position);
}

// rotate or shift stack_b, while content not in position place
void	move_to_top(t_list **stack_b, int position)
{	
	int	move;
	int	size;

	if (position == 0)
		return ;

	size = lstsize(*stack_b);
	if (position <= size/2)
	{
		printf("en dessous de la moitié\n : %i\n", position);
		while (position--)
			action(stack_b, stack_b, "rb");
	}
	else
	{
		//cas pair
		move = size - position;
		printf("au dessus de la moitié\n : %i\n", move);
		while (move--)
			//action(stack_b, stack_b, "rrb");
			action(stack_b, stack_b, "rrb");
			
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

void	sort_3(t_list *a)
{
	if (a->content < a->next->next->content && a->content > a->next->content)
		ft_putendl_fd("sa", 1);
	if (a->content > a->next->content
		&& a->next->content > a->next->next->content)
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("rra", 1);
	}
	if (a->next->next->content > a->next->content
		&& a->content > a->next->next->content)
		ft_putendl_fd("ra", 1);
	if (a->content < a->next->next->content && a->content < a->next->content)
	{
		ft_putendl_fd("sa", 1);
		ft_putendl_fd("ra", 1);
	}
	if (a->content < a->next->content && a->content > a->next->next->content)
		ft_putendl_fd("rra", 1);
}
