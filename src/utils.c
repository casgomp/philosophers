/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:19:36 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 14:02:15 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

int	philo_init_atoi(char *arg, unsigned int *dest)
{
	int	error;

	error = 0;
	*dest = ft_atoi_safe(arg, &error);
	return (!error);
}

int	ft_atoi_safe(const char *nptr, int *error)
{
	unsigned int	i;
	int				sign;
	long			result;

	*error = 0;
	sign = 1;
	result = 0;
	i = 0;
	while (((nptr[i] >= '\t') && (nptr[i] <= '\r')) || (nptr[i] == ' '))
		i++;
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i ++;
	}
	result = ft_atoi_safe_digit(nptr, i, error, sign);
	if (*error)
		return (0);
	return ((int)result * sign);
}

unsigned int	ft_atoi_safe_digit(const char *nptr, 
						int i, int *error, int sign)
{
	int				digit;
	unsigned int	result;

	result = 0;
	digit = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digit = nptr[i] - '0';
		if (sign == 1)
		{
			if (result > ((unsigned int)INT_MAX - digit) / 10)
				return (*error = 1, 0);
		}
		else
		{
			if (result > ((unsigned int)INT_MAX + 1 - digit) / 10)
				return (*error = 1, 0);
		}
		result = result * 10 + digit;
		i ++;
	}
	return (result);
}
