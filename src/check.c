/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:40:17 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/27 17:40:17 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sorted(int list[], int size)
{	
	int	i;

	i = -1;
	while (++i < size)
	{
		if (list[i] > list[i+1])
			return (0);
	}
	return (1);
}

void	lstdelete_front(t_list **lst)
{
	t_list	*list;

	list = *lst;
	*lst = (*lst)->next;
	(*lst)->previous = NULL;
	free(list);
}
