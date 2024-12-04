/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:15:04 by wiljimen          #+#    #+#             */
/*   Updated: 2024/11/14 14:21:49 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_arr(char **argv, char *str)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	ft_putstr_fd(str, 1);
	exit(EXIT_FAILURE);
}

void	print_error(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}

void	print_success(char *str)
{
	ft_printf(str);
	exit(EXIT_FAILURE);
}

void	print_list(t_list **lst, char c)
{
	t_list	*current;

	if (!lst || !*lst)
	{
		ft_printf("Stack %c empty\n", c);
		return ;
	}
	ft_printf("Stack %c\n", c);
	current = *lst;
	while (current != NULL)
	{
		ft_printf("%d\n", *(int*)current->content);
		current = current->next;
	}
	ft_printf("\n");
}

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