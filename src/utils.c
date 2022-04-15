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

#include "../include/push_swap.h"
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
		if ((res * 10 > INT_MAX) && neg == 1)
			exit_error(stack_a);
		if ((res * 10 - 1 > INT_MAX) && neg == -1)
			exit_error(stack_a);
		res = res * 10 + str[i++] - '0';
	}
	if (str[i] != '\0' || ((str[0] == '-' || str[0] == '+') && i == 1))
		exit_error(stack_a);
	return ((int)(res * neg));
}

void	exit_error(t_list *stack_a)
{
	ft_putendl_fd("Error", 2);
	if (!stack_a->is_empty)
		lstclear(&stack_a);
	exit(EXIT_FAILURE);
}
