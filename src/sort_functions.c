/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:23 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/11 20:03:58 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// TIENES QUE ARREGLAR LOS NUMEROS MAS PEQUEÑOS
// PORFABOL
void sort_aux(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*temp;
	int		i;
	int		size;

	temp = *stack_a;
	i = 0;
	size = ft_lstsize(*stack_a);
	while (temp && temp->index != index)
	{
		temp = temp->next;
		i++;
	}
	if (i <= size / 2)
		while (i--)
			rotate(stack_a, 'a');
	else
		while (i++ < size)
			rev_rotate(stack_a, 'a');
	push_b(stack_a, stack_b);
}

void	sort_three_num(t_list **stack)
{
	int f = *(int *)(*stack)->content;
	int s = *(int *)(*stack)->next->content;
	int t = *(int *)(*stack)->next->next->content;

	if (f > s && s < t && t > f)
		swap(stack, 'a');
	else if (f > s && s > t)
	{
		swap(stack, 'a');
		rev_rotate(stack, 'a');
	}
	else if (f > s && s < t)
		rotate(stack, 'a');
	else if (f < s && s > t && t > f)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if (f < s && s > t && t < f)
		rev_rotate(stack, 'a');
}



void	sort_four_num(t_list **stack_a, t_list **stack_b)
{
	sort_aux(stack_a, stack_b, 0);
	sort_three_num(stack_a);
	push_a(stack_b, stack_a);
}

void	sort_five_num(t_list **stack_a, t_list **stack_b)
{
	sort_aux(stack_a, stack_b, 0);
	sort_aux(stack_a, stack_b, 1);
	sort_three_num(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
}
