/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:23 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/19 15:12:59 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_aux(t_list **stack_a, t_list **stack_b, int index, int num)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index == index)
		{
			if (i == 2)
				rotate(stack_a, 'a');
			if (i == 1 || i == 2)
				swap(stack_a, 'a');
			if (i == 3)
				rev_rotate(stack_a, 'a');
			if ((i == 4 || i == 3) && index == 0 && num != 4)
				rev_rotate(stack_a, 'a');
			push(stack_a, stack_b, 'b');
			break ;
		}
		i++;
		temp = temp->next;
	}
}

void	sort_three_num(t_list **stack)
{
	int	f;
	int	s;
	int	t;

	f = *(int *)(*stack)->content;
	s = *(int *)(*stack)->next->content;
	t = *(int *)(*stack)->next->next->content;
	if (f > s && s < t && t < f)
		rotate(stack, 'a');
	else if (f < s && s > t && t < f)
		rev_rotate(stack, 'a');
	else if (f > s && s < t && t > f)
		swap(stack, 'a');
	else if (f > s && s > t && t < f)
	{
		swap(stack, 'a');
		rev_rotate(stack, 'a');
	}
	else if (f < s && s > t && t > f)
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}

void	sort_four_num(t_list **stack_a, t_list **stack_b)
{
	sort_aux(stack_a, stack_b, 0, 4);
	sort_three_num(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_five_num(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = 0;
	while (index <= 1)
	{
		sort_aux(stack_a, stack_b, index, 5);
		index++;
	}
	sort_three_num(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');

}
