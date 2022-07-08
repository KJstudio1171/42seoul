/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junekim <june1171@naver.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:44:25 by junekim           #+#    #+#             */
/*   Updated: 2022/07/08 10:09:37 by junekim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_stack {
	int				data;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_info {
	t_stack	*a_head;
	t_stack	*a_tail;
	t_stack	*b_head;
	t_stack	*b_tail;
	int		a_num;
	int		b_num;
	int		len;
	int		*sorted_arr;
	int		checker;
}				t_info;

void	pa(t_info *info);
void	pb(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);

void	push_a(t_info *info, t_stack *stack);
void	push_b(t_info *info, t_stack *stack);
t_stack	*new_stack(int data);
void	init_info(t_info *info, int len, int checker);
void	free_stacks(t_info *info);

void	print_op(t_info *info, char *string);
void	print_stack(t_info *info);
void	print_arr(int *arr, int len);
void	print_info(t_info	*info);

void	swap(int *a, int *b);
int		min_data(t_stack *head, int len);
int		max_data(t_stack *head, int len);

void	sort_low_number(t_info *info, int num);

int		is_sorted(t_info *info);
void	find_pivot(t_info *info, int *pivot, int min, int num);
void	reverse_rotate(t_info *info, int op1, int op2);

void	quicksort_stack_a(t_info *info, int num);
void	quicksort_stack_b(t_info *info, int num);

void	print_error(void);

int		*init_arr(t_info *info);

int		is_inputable(int argc, char **argv);

char	*get_next_line(int fd);

#endif