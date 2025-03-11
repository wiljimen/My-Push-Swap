/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 17:14:55 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/11 20:18:42 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_list **stack, char c)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	ft_lstadd_back(stack, first);
	first->next = NULL;
	*stack = second;
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
}

void	rotate_r(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');
}

void	rev_rotate(t_list **stack, char c)
{
	t_list	*first;
	t_list	*last_node;
	t_list	*pre_last_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last_node = ft_lstlast(first);
	pre_last_node = first;
	while (pre_last_node->next->next)
		pre_last_node = pre_last_node->next;
	ft_lstadd_front(stack, last_node);
	pre_last_node->next = NULL;
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
}

void	rev_rr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a, 'c');
	rev_rotate(stack_b, 'c');
	ft_putendl_fd("rrr", 1);
}
