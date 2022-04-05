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

t_list	*lst_init(int argc, char **argv, t_list *lst)
{
	int	i;

	i = 1;
	lst = lstnew(ft_atoi(argv[i]));
	while (i++ < argc - 1)
		lstadd_back(&lst, lstnew(ft_atoi(argv[i])));
	return (lst);
}
