/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperraud <bperraud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 18:47:22 by bperraud          #+#    #+#             */
/*   Updated: 2022/03/27 18:47:22 by bperraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stdlib.h"
#include "stdio.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;



//utils
t_list	*lst_init(int argc, char **argv, t_list *lst);

//list
void	lst_print(t_list *lst);
void	lstadd_back(t_list **alst, t_list *new);
void	lstadd_front(t_list **alst, t_list *new);
t_list	*lstlast(t_list *lst);
t_list	*lstnew(void *content);
int		lstsize(t_list *lst);
void	lstdel_front(t_list *lst);
void	lstclear(t_list **lst);
