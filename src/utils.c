/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:19:36 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/05 19:07:52 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

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

void print_error_args(int n)
{
	char	**msg;

	msg = NULL;
	if (n == 1)
	{
		msg = malloc(sizeof(char *) * 7);
		if (!msg)
			return;
		msg[0] = "Input ./executable + the following options:";
		msg[1] = "1) number_of_philosophers";
		msg[2] = "2) time_to_die (in milliseconds)";
		msg[3] = "3) time_to_eat (in milliseconds)";
		msg[4] = "4) time_to_sleep (in milliseconds)";
		msg[5] = "5) number_of_times_each_philosopher_must_eat (optional argument)";
		printf("%s\n%s\n%s\n%s\n%s\n%s\n",msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	}
	free (msg);
}
