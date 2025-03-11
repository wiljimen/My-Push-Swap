/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:00:42 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/11 20:01:47 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push_a(t_list **stack_from, t_list **stack_dst)
{
	if (!stack_from || !*stack_from || !stack_dst)
		return ;
	t_list	*tmp;

	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_dst, tmp);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_list **stack_from, t_list **stack_dst)
{
	if (!stack_from || !*stack_from || !stack_dst)
		return ;
	t_list	*tmp;

	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_dst, tmp);
	ft_putendl_fd("pb", 1);
}
