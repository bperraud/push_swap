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
#include "../libft/get_next_line.h"

static void	double_action(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, "rrr\n"))
	{
		r_rotate(stack_a);
		r_rotate(stack_b);
	}
	else if (!ft_strcmp(action, "rr\n"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (!ft_strcmp(action, "ss\n"))
	{
		swap(*stack_b);
		swap(*stack_a);
	}
	else
	{
		printf("action :%s\n", action);
		printf("strlen :%li\n", ft_strlen(action));
		ft_putendl_fd("pas normal", 2);
		ft_putendl_fd("Error", 2);
		free_exit(stack_a, stack_b);
	}
}

void	action(t_list **stack_a, t_list **stack_b, char *action)
{
	if (!ft_strcmp(action, "sa\n"))
		swap(*stack_a);
	else if (!ft_strcmp(action, "sb\n"))
		swap(*stack_b);
	else if (!ft_strcmp(action, "pa\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(action, "pb\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(action, "rra\n"))
		r_rotate(stack_a);
	else if (!ft_strcmp(action, "rrb\n"))
		r_rotate(stack_b);
	else if (!ft_strcmp(action, "ra\n"))
		rotate(stack_a);
	else if (!ft_strcmp(action, "rb\n"))
		rotate(stack_b);
	else
		return (double_action(stack_a, stack_b, action));
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

static void	checker(t_list **stack_a, t_list **stack_b)
{
	char	*act;

	act = get_next_line(0);
	while (act)
	{
		action(stack_a, stack_b, act);
		free(act);
		act = get_next_line(0);
	}
	free(act);
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
