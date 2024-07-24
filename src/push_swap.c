/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:51:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/07/24 19:00:16 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	check_args(argc, argv);
	t_list	**list;
	int		i;

	i = 1;
	list = malloc(sizeof(t_list));
	while (i < argc)
	{
		stack_creator(argv[i], list);
		i++;
	}
	
	// print_list(list);
}
