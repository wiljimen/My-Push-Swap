/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sort_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:26:41 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/04 19:51:57 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_sorted(t_list **stack)
{
	t_list	*node;

	node = *stack;
	while (node && node->next)
	{
		if (*(int *)node->content > *(int *)node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	count_rotations(t_list *stack, int max_index)
{
	int	i;
	
	i = 0;
	while (stack && stack->index != max_index)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	great_sort_aux(t_list **stack_a, t_list **stack_b, int num)
{
	int	i;
	int	range;

	i = 0;
	range = ft_sqrt(num) * 7 / 5;
	while(*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, 'b');
			rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}

void	great_sort(t_list **stack_a, t_list **stack_b, int num)
{
	int	rb_count;
	int	rev_rb_count;

	great_sort_aux(stack_a, stack_b, num);
	while (num - 1 >= 0)
	{
		rb_count = count_rotations(*stack_b, (num - 1));
		rev_rb_count = num - rb_count;
		if (rb_count <= rev_rb_count)
		{
			while ((*stack_b)->index != num - 1)
				rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			num--;
		}
		else
		{
			while ((*stack_b)->index != num - 1)
				rev_rotate(stack_b, 'b');
			push(stack_b, stack_a, 'a');
			num--;
		}
	}
}
