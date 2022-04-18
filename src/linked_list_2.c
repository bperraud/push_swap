/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:00:31 by bperraud          #+#    #+#             */
/*   Updated: 2022/04/05 19:00:31 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_list	*lst_init(int argc, char **argv)
{
	int		i;
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	lst = lstnew(atoi_lst(argv[1], lst));
	i = 1;
	while (i++ < argc - 1)
		lstadd_back(&lst, lstnew(atoi_lst(argv[i], lst)));
	return (lst);
}

void	lst_print(t_list *lst)
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

void	lstdel_front(t_list **lst)
{
	if (lstsize(*lst) == 1)
	{
		(*lst)->is_empty = 1;
		free((*lst)->previous);
		free((*lst)->next);
		return ;
	}
	*lst = (*lst)->next;
	free((*lst)->previous);
	(*lst)->previous = NULL;
}

void	lstclear(t_list **lst)
{
	t_list	*temp;

	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free(*lst);
			*lst = temp;
		}
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
