/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:48:34 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/19 15:02:03 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_all(char **argv, t_list **stack)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	if (stack && *stack)
		ft_lstclear(stack, free);
	exit(EXIT_FAILURE);
}

void	node_to_stack(t_list **stack_a, int number, char **split_arg)
{
	int		*num;
	t_list	*node;

	num = malloc(sizeof(int));
	if (!num)
		free_all(split_arg, stack_a);
	*num = number;
	node = ft_lstnew(num);
	if (!node)
	{
		free(num);
		free_all(split_arg, stack_a);
	}
	if (!ft_lstadd_back_aux(stack_a, node))
	{
		free(num);
		free(node);
		free_all(split_arg, stack_a);
	}
}

void	stack_creator(char *argv, t_list **stack_a)
{
	char	**split_arg;
	long	n;
	int		i;

	i = 0;
	split_arg = ft_split(argv, ' ');
	if (!split_arg)
		free_all(NULL, stack_a);
	while (split_arg[i])
	{
		n = ft_atol(split_arg[i]);
		n = control_long(n, split_arg[i]);
		node_to_stack(stack_a, (int)n, split_arg);
		free(split_arg[i]);
		i++;
	}
	free(split_arg);
}

void	stack_init(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		stack_creator(argv[i], stack_a);
		i++;
	}
}

void	principal_sort(t_list **stack_a, t_list **stack_b)
{
	int	num;

	num = ft_lstsize(*stack_a);
	get_min_index(stack_a);
	if (!is_stack_sorted(stack_a))
	{
		if (num == 2)
			swap(stack_a, 'a');
		else if (num == 3)
			sort_three_num(stack_a);
		else if (num == 4)
			sort_four_num(stack_a, stack_b);
		else if (num == 5)
			sort_five_num(stack_a, stack_b);
		else
			great_sort(stack_a, stack_b, num);
	}
}
