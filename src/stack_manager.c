/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:48:34 by wiljimen          #+#    #+#             */
/*   Updated: 2024/10/24 18:31:22 by wiljimen         ###   ########.fr       */
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
		n = control_long(n, split_arg[i]);
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
		free(split_arg[i]);
		i++;
	}
	free(split_arg);
}

void	print_list_index(t_list **list)
{
    t_list *current;
	
	current = *list;
    while (current != NULL)
    {
        ft_printf("Index: %d\n", current->index);
        current = current->next;
    }
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
	print_list_index(stack_a);
	if (!is_stack_sorted(stack_a))
	{
		if (num == 2)
			swap(stack_a, 'a');
		else if (num == 3)
			sort_three_num(stack_a);
		else if (num == 4)
			sort_four_num(stack_a, stack_b);
	}
}

