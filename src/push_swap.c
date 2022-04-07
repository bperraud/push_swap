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

void	push_swap(t_list *stack_a)
{
	int	size;

	size = lstsize(stack_a);



	if (size == 2)
		ft_putendl_fd("sa", 1);
	else if (size == 3)
		three_push_swap(stack_a);

}

void	instruction(t_list *a, char *text)
{
	ft_putendl_fd(text, 1);
	if (ft_strncmp(text, "sa", 2))
		;
		//push(a, b);;
}

void	three_push_swap(t_list *a)
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

void	sort(t_list *a)
{
	;
}
