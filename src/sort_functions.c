/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/10/29 17:08:34 by wiljimen         ###   ########.fr       */
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

void	sort_aux(t_list **stack_a, t_list **stack_b, int index)
{
	t_list	*temp;
	int		ind;

	ind = 0;
	temp = *stack_a;
	printf("Index temp");
	print_list_index(&temp);
	while(temp)
	{
		if (temp->index == index)
		{
			if (ind == 1)
				swap(stack_a, 'a');
			else if (ind == 2)
				rotate(stack_a, 'a');
			else if (ind == 3)
				rev_rotate(stack_a, 'a');
			push(stack_a, stack_b, 'b');
			break ;
		}
		ind++;
		temp = temp->next;
	}
}

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
	if ((f > s) && (s < t) && (t < f))
		rotate(stack, 'a');
	else if ((f < s) && (s > t) && (t < f))
		rev_rotate(stack, 'a');
	else if ((f > s) && (s < t) && (t > f))
		swap(stack, 'a');
	else if ((f > s) && (s > t) && (t < f))
	{
		swap(stack, 'a');
		rev_rotate(stack, 'a');
	}
	else if ((f < s) && (s > t) && (t > f))
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}


void	sort_four_num(t_list **stack_a, t_list **stack_b)
{
	sort_aux(stack_a, stack_b, 0);
	sort_three_num(stack_a);
	push(stack_b, stack_a, 'a');
}

void	sort_five_num(t_list **stack_a, t_list **stack_b)
{
	int	index;

	index = 0;
	while (index <= 1)
	{
		sort_aux(stack_a, stack_b, index);
		index++;
	}
	sort_three_num(stack_a);
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
}
