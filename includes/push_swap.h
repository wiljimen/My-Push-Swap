/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/18 18:47:24 by wiljimen         ###   ########.fr       */
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

void	stack_creator(char *argv, t_list **stack_a);
void	stack_init(int argc, char **argv, t_list **stack_a);
void	print_list(t_list **lst, char c);
void	free_stack(t_list **stack);

// PARSE

void	check_args(int argc, char **argv);
void	print_error(char *str);
void	ft_free(char **map, char *str);
void	overflow_check(long n);
int		ft_isspace(int c);
long	control_long(long n, char *split_arg);
bool	has_duplicates(int argc, char **argv);

// MOVES

void	push(t_list **stack_from, t_list **stack_dst, char c);
void	swap(t_list **stack, char c);
void	rotate(t_list **stack, char *str);
void	rev_rotate(t_list **stack, char *str);
void	ft_rr(t_list **stack_a, t_list **stack_b);

// ALGORITHM

void	get_min_index(t_list **stack);
void	sort_three_num(t_list **stack);

#endif