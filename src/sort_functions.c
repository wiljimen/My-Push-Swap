/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/10/16 18:51:45 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_num(t_list **stack)
{
	t_list	*aux;
	int		f;
	int		s;
	int		t;

	aux = *stack;
	f = *((int *)aux->content);
	s = *((int *)aux->next->content);
	t = *((int *)aux->next->next->content);
	if (f > s && s > t)
	{
		swap(stack, 'a');
		rev_rotate(stack, "sa");
	}
	else if (f > t && t > s)
	{
		swap(stack, 'a');
		rotate(stack, "a");
	}
	else if (t < f && f > s)
		rotate(stack, "a");
	else if ((f > s) && (s < t) && (t > f))
		swap(stack, 'a');
	else if ((f < s) && (s > t) && (t > f))
		rev_rotate(stack, "sa");
}

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

void	mini_sort(t_list **stack_a, t_list **stakc_b, int index, int size)
{
	t_list	*temp;
	int		ind;

	ind = 0;
	temp = *stack_a;
	while(temp)
	{
		if (temp->index == index)
		{
			if (ind = 2)
				rotate(stack_a, 'a');
			else if (ind == 1 || ind == 2)
				swap(stack_a, 'a');
			else if (ind == 3)
				rev_rotate(stack_a, 'a');
			else if ((ind == 4 || ind == 3) && index == 0 && size != 4)
				rev_rotate(stack_a, 'a');
			push(stack_a, stack_b, 'b');
			break ;
		}
		ind++;
		temp = temp->next;
	}
}

void	sort_four_num(t_list **stack_a, t_list **stack_b)
{
	mini_sort(stack_a, stack_b, 0, 4);
	sort_three_num(stack_a);
	push(stack_b, stack_a, 'a');
}