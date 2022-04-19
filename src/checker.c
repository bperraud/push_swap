/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 03:12:23 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/18 03:12:23 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"
#include "../libft/get_next_line_bonus.h"


int	double_action(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strncmp(action, "rrr", 3))
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
	else if (!ft_strncmp(action, "rr\n", 3))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strncmp(action, "ss\n", 3))
	{
		swap(*stack_b);
		swap(*stack_a);
	}
	else
		return (0);
	return (1);
}

int	action(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strncmp(action, "sa\n", 3))
		swap(*stack_a);
	else if (!ft_strncmp(action, "sb\n", 3))
		swap(*stack_b);
	else if (!ft_strncmp(action, "pa\n", 3))
		push(stack_b, stack_a);
	else if (!ft_strncmp(action, "pb\n", 3))
		push(stack_a, stack_b);
	else if (!ft_strncmp(action, "rra", 3))
		r_rotate(stack_a);
	else if (!ft_strncmp(action, "rrb", 3))
		r_rotate(stack_b);
	else if (!ft_strncmp(action, "ra\n", 3))
		rotate(stack_a);
	else if (!ft_strncmp(action, "rb\n", 3))
		rotate(stack_b);
	else
		return (double_action(stack_a, stack_b, action));
	return (1);
}

void	lst_print(t_list *lst)		// penser a supprimer
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

/*
static void	checker(t_list *stack_a, t_list *stack_b)

{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (!action(&stack_a, &stack_b, op))
		{
			ft_putendl_fd("Error", 2);
			free_exit(&stack_a, &stack_b);
		}
		free(op);
		op = get_next_line(0);
	}

	if (op)
		free(op);

}
*/

static void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		if (!action(stack_a, stack_b, op))
		{
			ft_putendl_fd("Error", 2);
			free_exit(stack_a, stack_b);
		}
		free(op);
		op = get_next_line(0);
	}
	free(op);
}


int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = lst_init(argc, argv);
	stack_b = malloc(sizeof(t_list));
	stack_b->is_empty = 1;
	if (has_dupplicate(stack_a))
	{
		ft_putendl_fd("Error", 2);
		free_exit(&stack_a, &stack_b);
	}
	if (is_sorted(stack_a))
		free_exit(&stack_a, &stack_b);

	checker(&stack_a, &stack_b);

	if (is_sorted(stack_a))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_exit(&stack_a, &stack_b);
	return (0);
}
