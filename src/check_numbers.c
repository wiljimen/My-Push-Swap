/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:02:16 by wiljimen          #+#    #+#             */
/*   Updated: 2024/07/24 19:00:00 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	overflow_check(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		print_error("Overflow\n");
}

long	zero_control(char *argv)
{
	long	i;
	long	n;
	int		sign;

	i = 0;
	sign = 1;
	if (argv[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (argv[i] && argv[i] == '0')
		i++;
	n = ft_atol(argv + i);
	return (n * sign);
}

long	control_long(long n, char *split_arg)
{
	n = zero_control(split_arg);
	overflow_check(n);
	return (n);
}

bool	has_duplicates(int argc, char **argv)
{
	long	num1;
	long	num2;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		num1 = ft_atol(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num2 = ft_atol(argv[j]);
			if (num1 == num2)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
