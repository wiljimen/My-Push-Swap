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