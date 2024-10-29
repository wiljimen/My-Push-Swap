/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:00:42 by wiljimen          #+#    #+#             */
/*   Updated: 2024/10/24 20:00:24 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_list **stack_from, t_list **stack_dst, char c)
{
	if (!stack_from || !*stack_from || !stack_dst)
		return ;
	t_list	*tmp;

	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_dst, tmp);
	ft_printf("p%c\n", c);
}
