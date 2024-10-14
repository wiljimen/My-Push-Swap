/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:17:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/18 18:26:57 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_min_index(t_list **stack)
{
	t_list	*current;
	t_list	*tmp;
	int		min_index;

	current = *stack;
	while (current)
	{
		tmp = *stack;
		min_index = 0;
		while(tmp)
		{
			if (*(int *)current->content > *(int *)tmp->content)
				min_index++;
			tmp = tmp->next;
		}
		current->index = min_index;
		current = current->next;
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