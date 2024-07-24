/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/07/24 18:30:29 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define READ_END 0
# define WRITE_END 1

# include "libft.h"
# include <sys/wait.h>
# include <stdbool.h>

void	stack_creator(char *argv, t_list **list);
void	print_error(char *str);
void	check_args(int argc, char **argv);
void	ft_free(char **map, char *str);
void	overflow_check(long n);
int		ft_isspace(int c);
long	control_long(long n, char *split_arg);
bool	has_duplicates(int argc, char **argv);

#endif