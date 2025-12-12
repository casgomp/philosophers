/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:24:52 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 18:42:47 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

void print_error_args(void)
{
	char	**msg;

	msg = NULL;
	{
		msg = malloc(sizeof(char *) * 7);
		if (!msg)
			return;
		msg[0] = "Input ./executable + the following options:";
		msg[1] = "1) number_of_philosophers (>1)";
		msg[2] = "2) time_to_die (in milliseconds)";
		msg[3] = "3) time_to_eat (in milliseconds)";
		msg[4] = "4) time_to_sleep (in milliseconds)";
		msg[5] = "5) number_of_times_each_philosopher_must_eat (optional argument)";
		printf("%s\n%s\n%s\n%s\n%s\n%s\n",msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	}
	free (msg);
}

void    print_critical(t_philo *philos, char *str)
{
    pthread_mutex_lock(&philos->phargs->mutxprint);
    if (philos->phargs->state != 1)
        printf("%dms %d %s\n", get_time_relative(philos->phargs), philos->idxph + 1, str);
    pthread_mutex_unlock(&philos->phargs->mutxprint);
}

void    state_critical(t_phargs *phargs)
{
    pthread_mutex_lock(&phargs->mutxstate);
    phargs->state = 1;
    pthread_mutex_unlock(&phargs->mutxstate);
}

int check_state(t_philo *philos)
{
    pthread_mutex_lock(&philos->phargs->mutxstate);
    if (philos->phargs->state == 1)
        return (pthread_mutex_unlock(&philos->phargs->mutxstate), 1);
    pthread_mutex_unlock(&philos->phargs->mutxstate);
    return (0);
}

void	print_end_simulation(t_phargs *phargs, void *retval)
{
    pthread_mutex_lock(&phargs->mutxprint);
	if ((uintptr_t)retval == 2)
		printf("%dms %d died\n", get_time_relative(phargs), phargs->dead + 1);
	else if ((uintptr_t)retval == 3)
		printf("%dms philosophers have finished eating\n", get_time_relative(phargs));
    pthread_mutex_unlock(&phargs->mutxprint);
}