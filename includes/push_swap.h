/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:22 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/04 19:56:59 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define READ_END 0
# define WRITE_END 1

# include "libft.h"
# include <sys/wait.h>
# include <stdbool.h>

typedef struct s_stack
{
	t_list	**stack_b;
	t_list	**stack_a;
	
}			t_stack;

// STACKS

void	node_to_stack(t_list **stack_a, int number, char **split_arg);
void	stack_creator(char *argv, t_list **stack_a);
void	stack_init(int argc, char **argv, t_list **stack_a);
void	free_stack(t_list **stack);
int		ft_lstadd_back_aux(t_list **lst, t_list *new);

// PARSE

void	check_args(int argc, char **argv);
void	free_arr(char **map, char *str);
void	free_all(char **argv, t_list **stack);
void	overflow_check(long n);
int		ft_isspace(int c);
long	control_long(long n, char *split_arg);
bool	has_duplicates(int argc, char **argv);
void	print_error(char *str);
void	print_list(t_list **lst, char c);

// MOVES

void	push(t_list **stack_from, t_list **stack_dst, char c);
void	swap(t_list **stack, char c);
void	rotate(t_list **stack, char c);
void	rev_rotate(t_list **stack, char c);
void	ft_rr(t_list **stack_a, t_list **stack_b);

// ALGORITHM

int		is_stack_sorted(t_list **stack);
void	get_min_index(t_list **stack);
void	sort_three_num(t_list **stack);
void	sort_aux(t_list **stack_a, t_list **stack_b, int index);
void	sort_four_num(t_list **stack_a, t_list **stack_b);
void	sort_five_num(t_list **stack_a, t_list **stack_b);
void	principal_sort(t_list **stack_a, t_list **stack_b);
int		count_rotations(t_list *stack, int max_index);
void	great_sort_aux(t_list **stack_a, t_list **stack_b, int num);
void	great_sort(t_list **stack_a, t_list **stack_b, int num);

#endif