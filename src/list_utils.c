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

#include "../include/push_swap.h"

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

int	lstmax(t_list *lst)
{
	int	max;

	max = INT_MIN;
	if (lst)
	{
		while (lst)
		{
			if (lst->content > max)
				max = lst->content;
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
			if (lst->content < min)
				min = lst->content;
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
			if (lst->content < min)
			{
				min = lst->content;
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
			if (lst->content > max)
			{
				max = lst->content;
				position = pos;
			}
			lst = lst->next;
			pos += 1;
		}
	}
	return (position);
}
