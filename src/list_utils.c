/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 02:01:46 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/18 02:01:46 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstmax(t_list *lst)
{
	int	max;

	max = INT_MIN;
	if (lst)
	{
		while (lst)
		{
			if (lst->cont > max)
				max = lst->cont;
			lst = lst->next;
		}
	}
	return (max);
}

int	lstmin(t_list *lst)
{
	int	min;

	min = INT_MAX;
	if (lst)
	{
		while (lst)
		{
			if (lst->cont < min)
				min = lst->cont;
			lst = lst->next;
		}
	}
	return (min);
}

int	lstmin_position(t_list *lst)
{
	int	min;
	int	position;
	int	pos;

	min = INT_MAX;
	position = 0;
	pos = 0;
	if (lst)
	{
		while (lst)
		{
			if (lst->cont < min)
			{
				min = lst->cont;
				position = pos;
			}
			lst = lst->next;
			pos += 1;
		}
	}
	return (position);
}

int	lstmax_position(t_list *lst)
{
	int	max;
	int	position;
	int	pos;

	max = INT_MIN;
	position = 0;
	pos = 0;
	if (lst)
	{
		while (lst)
		{
			if (lst->cont > max)
			{
				max = lst->cont;
				position = pos;
			}
			lst = lst->next;
			pos += 1;
		}
	}
	return (position);
}
