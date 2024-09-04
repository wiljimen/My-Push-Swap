/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:48:34 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/04 08:38:46 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_creator(char *argv, t_list **stack_a, int j)
{
	char	**split_arg;
	long	n;
	t_list	*node;
	int		*num;

	split_arg = ft_split(argv, ' ');
	n = ft_atol(split_arg[j]);
	while (split_arg[j])
	{
		if (!n)
			ft_free(split_arg, "Bad malloc");
		n = control_long(n, split_arg[j]);
		num = malloc(sizeof(int));
		if (!num)
			ft_free(split_arg, "Error num");
		*num = (int)n;
		node = ft_lstnew(num);
		if (!node)
		{
			free(num);
			ft_free(split_arg, "Bad node");
		}
		ft_lstadd_back(stack_a, node);
		free(split_arg[j]);
		j++;
	}
	free(split_arg);
}

void	stack_push(t_list **stack_a, t_list **stack_b)
{
	if (stack_a == NULL || *stack_a == NULL)
		return ;
	t_list	*node;

	node = *stack_a;
	printf("Nodo en a: %d\n", *(int *)node->content);
	*stack_a = (*stack_a)->next;
    node->next = *stack_b;
    *stack_b = node;
	printf("Nodo en b: %d\n", *(int *)node->content);
}

void	stack_init(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	
	i = 1;
	j = 0;
	while (i < argc)
	{
		stack_creator(argv[i], stack_a, j);
		i++;
	}
	while(*stack_a != NULL)
		stack_push(stack_a, stack_b);
}