/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:51:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/11/14 14:11:40 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		print_error("Invalid arguments");
	if (has_duplicates(argc, argv))
		print_error("Error: Duplicated number");
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
				print_error("Error\n");
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	if (argc > 2)
		stack_init(argc, argv, &stack_a);
	else
		return (0);
	ft_printf("\nAntes de ordenar\n\n");
	print_list(&stack_a, 'a');
	print_list(&stack_b, 'b');
	principal_sort(&stack_a, &stack_b);
	ft_printf("\nDespues de ordenar\n\n");
	print_list(&stack_a, 'a');
	print_list(&stack_b, 'b');
	return (0);
}
