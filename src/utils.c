/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:13:08 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/05 20:13:08 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

int	atoi_lst(const char *str, t_list *stack_a)
{
	int				i;
	int				neg;
	long long int	res;

	neg = 1;
	res = 0;
	i = 0;
	if (str[i] == '-')
	{
		neg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		if ((res > INT_MAX) && neg == 1)
			exit_error(stack_a);
		if ((res - 1 > INT_MAX) && neg == -1)
			exit_error(stack_a);
	}
	if (str[i] != '\0' || ((str[0] == '-' || str[0] == '+') && i == 1))
		exit_error(stack_a);
	return ((int)(res * neg));
}

void	free_exit(t_list **stack_a, t_list **stack_b)
{
	lstclear(stack_a);
	lstclear(stack_b);
	exit(EXIT_SUCCESS);
}

void	exit_error(t_list *stack_a)
{
	ft_putendl_fd("Error", 2);
	lstclear(&stack_a);
	exit(EXIT_FAILURE);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
