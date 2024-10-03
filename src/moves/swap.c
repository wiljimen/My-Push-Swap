/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:21:05 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/18 18:43:53 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_list **stack_from, char c)
{
	t_list	*first;
	t_list	*second;

	if (!*stack_from || (*stack_from)->next == NULL)
		return;
	first = *stack_from;
	second = (*stack_from)->next;
	first->next = second->next;
	second->next = first;
	*stack_from = second;
	printf("s%c\n", c);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
}