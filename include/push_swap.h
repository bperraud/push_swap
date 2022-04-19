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
#include "limits.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
	struct s_list	*previous;
	int				is_empty;
}	t_list;


typedef struct s_best
{
	int				min_operation;
	int				move_to_end_b;
	int				move_to_end_a;
}	t_best;

//main
void	action(t_list **stack_a, t_list **stack_b, char *action);

//check
int		has_dupplicate(t_list *lst);
int		is_sorted(t_list *lst);

//operation
void	swap(t_list *lst);
void	push(t_list **a, t_list **b);
void	rotate(t_list **lst);
void	r_rotate(t_list **lst);

//utils
void	exit_error(t_list *stack_a);
int		atoi_lst(const char *str, t_list *stack_a);
int		max(int a, int b);
int		min(int a, int b);
void	free_exit(t_list **stack_a, t_list **stack_b);

//list
void	lst_print(t_list *lst);
void	lstadd_back(t_list **alst, t_list *new);
void	lstadd_front(t_list **alst, t_list *new);
t_list	*lstlast(t_list *lst);
t_list	*lstnew(int content);
int		lstsize(t_list *lst);
void	lstdel_front(t_list **lst);
void	lstclear(t_list **lst);
int		lstmax(t_list *lst);
int		lstmax_position(t_list *lst);
int		lstmin_position(t_list *lst);
int		lstmin(t_list *lst);
t_list	*lst_init(int argc, char **argv);

//push_swap
void	push_swap(t_list **stack_a, t_list **stack_b);
int		find_elem_max(t_list *stack_b, int compare);
int		find_elem_min(t_list *stack_b, int compare);
void	move_to_top_b(t_list **stack_b, int position);
void	move_to_top_a(t_list **stack_a, int position);

//sort
void	sort_until_2(t_list **stack_a, t_list **stack_b, int size);
void	short_sort(t_list **stack_a, t_list **stack_b, int size);
void	sort_3(t_list **a);
void	sort_4(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);

//optimisation
t_best	best_operation_top_half(t_list *stack_a, t_list *stack_b);
t_best	best_operation_bot_half(t_list *stack_a, t_list *stack_b);
void	move_to_top_opti(t_list **stack_a, t_list **stack_b, t_best best);
void	move_to_bot_opti(t_list **stack_a, t_list **stack_b, t_best best);
