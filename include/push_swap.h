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


//push_swap


//main
int		check_argument(int argc, char **argv);
int		is_sorted(t_list *lst);

//check
int		has_dupplicate(t_list *lst);


//operation
void	swap(t_list *lst);
void	push(t_list **a, t_list **b);
void	rotate(t_list **lst);


//utils
void	exit_error(t_list *stack_a, t_list *stack_b);
int		atoi_lst(const char *str, t_list *stack_a);
t_list	*lst_init(int argc, char **argv);

//list
void	lst_print(t_list *lst);
void	lstadd_back(t_list **alst, t_list *new);
void	lstadd_front(t_list **alst, t_list *new);
t_list	*lstlast(t_list *lst);
t_list	*lstnew(void *content);
int		lstsize(t_list *lst);
void	lstdel_front(t_list **lst);
void	lstclear(t_list **lst);
