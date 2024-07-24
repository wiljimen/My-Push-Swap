/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:48:34 by wiljimen          #+#    #+#             */
/*   Updated: 2024/07/24 18:59:56 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_creator(char *argv, t_list **list)
{
	int		i;
	char	**split_arg;
	long	n;
	t_list	*node;

	i = 0;
	split_arg = ft_split(argv, ' ');
	n = ft_atol(split_arg[i]);
	while (split_arg[i])
	{
		if (!n)
			ft_free(split_arg, "Bad malloc");
		n = control_long(n, split_arg[i]);
		node = ft_lstnew(&n);
		if (!node)
			ft_free(split_arg, "Bad node");
		ft_lstadd_back(list, node);
		ft_printf("Numero en nodo:%d\n", *(int *)node->content);
		free(split_arg[i]);
		i++;
	}
	free(split_arg);
}

void	