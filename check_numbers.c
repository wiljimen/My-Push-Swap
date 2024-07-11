/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiljimen <wiljimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:02:16 by wiljimen          #+#    #+#             */
/*   Updated: 2024/07/11 16:11:29 by wiljimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void overflow_check(long n)
{
	if (n > INT_MAX || n < INT_MIN)
		print_error("Overflow\n");
}

int	zero_control(char *argv)
{
	int	i;
	int	sign;
	
	i = 0;
	sign = 0;
	while (argv[i])
	{
		if (argv[i] == '-')
			sign++;
		while()
			
	}
}