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

t_list	*lst_init(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	lst = lstnew(atoi_lst(argv[1], lst));
	i = 1;
	while (i++ < argc - 1)
		lstadd_back(&lst, lstnew(atoi_lst(argv[i], lst)));
	return (lst);
}


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
			exit_error(stack_a, NULL);
		if ((res * 10 - 1 > INT_MAX) && neg == -1)
			exit_error(stack_a, NULL);
		res = res * 10 + str[i++] - '0';
	}
	if (str[i] != '\0' || ((str[0] == '-' || str[0] == '+') && i == 1))
		exit_error(stack_a, NULL);
	return ((int)(res * neg));
}


void	exit_error(t_list *stack_a, t_list *stack_b)
{
	ft_putendl_fd("Error", 2);
	lstclear(&stack_a);
	lstclear(&stack_b);
	exit(EXIT_FAILURE);
}
