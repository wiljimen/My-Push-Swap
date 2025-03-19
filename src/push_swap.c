/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:51:23 by wiljimen          #+#    #+#             */
/*   Updated: 2025/03/19 15:28:22 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list_index(t_list **list)
{
	t_list	*current;

	current = *list;
	while (current != NULL)
	{
		ft_printf("Index: %d\n", current->index);
		current = current->next;
	}
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

void	check_args(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	if (argc < 2 || argv[1][0] == '\0')
		exit(EXIT_FAILURE);
	if (has_duplicates(argc, argv))
		print_error("Error");
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+') &&
				ft_isdigit(argv[i][j + 1]))
				j++;
			else if (ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j]))
				j++;
			else
				print_error("Error");
		}
		i++;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp->content);
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	if (argc >= 2)
		stack_init(argc, argv, &stack_a);
	else
		return (0);
	principal_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
