/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 02:42:51 by bperraud          #+#    #+#             */
/*   Updated: 2022/01/16 22:00:56 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "libft.h"

int	ft_atoi(const char *str)
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
			exit_error();
		if ((res * 10 - 1 > INT_MAX) && neg == -1)
			exit_error();
		res = res * 10 + str[i++] - '0';
	}
	if (str[i] != '\0' || ((str[0] == '-' || str[0] == '+') && i == 1))
		exit_error();
	return ((int)(res * neg));
}
