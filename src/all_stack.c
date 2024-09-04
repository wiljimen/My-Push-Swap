/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:48:34 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/04 09:46:51 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// void	stack_creator(char *argv, t_list **stack_a)
// {
// 	int		i;
// 	char	**split_arg;
// 	long	n;
// 	t_list	*node;
// 	int		*num;

// 	i = 0;
// 	split_arg = ft_split(argv, ' ');
// 	n = ft_atol(split_arg[i]);
// 	while(split_arg[i])
// 	{
// 		if (!n)
// 			ft_free(split_arg, "Balloc");
// 		num = malloc(sizeof(int));
// 		n = control_long(n, split_arg[i]);
// 		*num = (int)n;
// 		node = ft_lstnew(num);
// 		if (!node)
// 			ft_free(split_arg, "Bad node");
// 		ft_lstadd_back(stack_a, node);
// 		ft_printf("Numero en nodo:%d\n", *(int *)(*stack_a)->content);
// 		free(split_arg[i]);
// 		i++;
// 	}
// 	free(split_arg);
// }

void	stack_creator(char *argv, t_list **stack_a)
{
	char	**split_arg;
	long	n;
	t_list	*node;
	int		*num;
	int		i;

	i = 0;
	split_arg = ft_split(argv, ' ');
	while (split_arg[i])
	{
		n = ft_atol(split_arg[i]);
		if (!n)
			ft_free(split_arg, "Bad malloc");
		n = control_long(n, split_arg[i]);
		num = malloc(sizeof(int));
		// if (!num)
		// 	ft_free(split_arg, "Error num");
		*num = (int)n;
		node = ft_lstnew(num);
		if (!node)
		{
			free(num);
			ft_free(split_arg, "Bad node");
		}
		ft_lstadd_back(stack_a, node);
		// ft_printf("Content: %d\n", *(int*)(*stack_a)->content);
		free(split_arg[i]);
		i++;
	}
	free(split_arg);
}

void	stack_init(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	int	i;
	
	i = 1;
	while (i < argc)
	{
		stack_creator(argv[i], stack_a);
		i++;
	}
	if (!stack_a || !*stack_a)
		return ;
	print_list(stack_a, 'a');
	while (*stack_a)
		push(stack_a, stack_b);
	print_list(stack_b, 'b');
}
