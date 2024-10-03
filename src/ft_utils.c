/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:15:04 by wiljimen          #+#    #+#             */
/*   Updated: 2024/09/11 17:21:18 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free(char **argv, char *str)
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

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	print_list(t_list **lst, char c)
{
	t_list	*current;
	
	if (!lst || !*lst)
	{
		ft_printf("Stack %c empty", c);
		return ;
	}
	ft_printf("Stack %c\n", c);
	current = *lst;
    while (current != NULL)
	{
        ft_printf("Content: %d\n", *(int*)current->content);
        current = current->next;
    }
	ft_printf("\n");
}

// void	free_stack(t_list **stack)
// {
// 	t_list	*temp;
// 	t_list	*next;

// 	temp = *stack;
// 	while (temp)
// 	{
// 		next = temp->next;
// 		free(temp->content);
// 		free(temp);
// 		temp = next;
// 	}
// 	*stack = NULL;
// }