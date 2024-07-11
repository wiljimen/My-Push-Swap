/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:52:22 by wiljimen          #+#    #+#             */
/*   Updated: 2024/07/11 16:49:05 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define READ_END 0
# define WRITE_END 1

# include "libft.h"
# include <sys/wait.h>

void	stack_creator(char *argv, t_list **list);
void	print_error(char *str);
void	check_args(int argc, char **argv);
void	ft_free(char **map, char *str);
void 	overflow_check(long n);
int		ft_isspace (int c);
long	control_long(long n, char *split_arg);

#endif