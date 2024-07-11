/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:51:23 by wiljimen          #+#    #+#             */
/*   Updated: 2024/07/11 16:16:41 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	stack_creator(char *argv, t_list **list)
{
	int		i;
	char	**split_arg;
	long	*n;
	t_list	*node;

	i = 0;
	split_arg = ft_split(argv, ' ');
	while(split_arg[i])
	{
		n = malloc(sizeof(long));
		if (!n)
			ft_free(split_arg, "Balloc");
		n = zero_control()
		n = ft_atol(split_arg[i]);
		overflow_check(*n);
		node = ft_lstnew(n);
		if (!node)
			ft_free(split_arg, "Bad node");
		ft_lstadd_back(list, node);
		ft_printf("%d\n", *(int *)node->content);
		free(split_arg[i]);
		free(n);
		i++;
	}
	free(split_arg);
}

void	check_args(int argc, char **argv)
{
	if (argc < 2 || argv[1][0] == '\0')
		print_error("Invalid arguments");
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while(argv[i][j])
		{	
			if ((argv[i][j] == '-' || argv[i][j] == '+') && 
				ft_isdigit(argv[i][j + 1]))
				j++;
			else if (ft_isdigit(argv[i][j]) || ft_isspace(argv[i][j]))
				j++;
			else
				print_error("Error\n");
			// printf("Caracter:%c\n", argv[i][j]);
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
