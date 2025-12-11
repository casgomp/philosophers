/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:57:38 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/11 20:33:48 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*routine_philo(void *arg)
{
    t_philo        *philos;
    unsigned int    nph;
    unsigned int    idx;

    unsigned int    left_fork_idx;
    unsigned int    right_fork_idx;
    pthread_mutex_t *fork_low;
    pthread_mutex_t *fork_high;

    philos = (t_philo *)arg;
    nph = philos->phargs->n_philos;
    idx = philos->idxph;

    left_fork_idx = philos->idxph;
    right_fork_idx = (philos->idxph + 1) % nph;
    if (left_fork_idx < right_fork_idx)
    {
        fork_low = &philos->phargs->mutxfrk[left_fork_idx];
        fork_high = &philos->phargs->mutxfrk[right_fork_idx];
    }
    else
    {
        fork_low = &philos->phargs->mutxfrk[right_fork_idx];
        fork_high = &philos->phargs->mutxfrk[left_fork_idx];
    }
    while (1)
    {
        print_critical(philos, "is thinking");
        pthread_mutex_lock(fork_low);
        print_critical(philos, "has taken a fork");
        pthread_mutex_lock(fork_high);
        print_critical(philos, "has taken a fork");
        usleep(philos->phargs->time_eat);
        print_critical(philos, "is eating");
        (philos->nteaten) ++;
        philos->tlasteat = get_time_relative(philos->phargs);
        //printf("philo %d has eaten %d times\n", idx + 1, philos->nteaten); //this printf statement is not part of the assignment.
        pthread_mutex_unlock(fork_high);
        pthread_mutex_unlock(fork_low);
        print_critical(philos, "is sleeping");
        usleep(philos->phargs->time_sleep);
        if ((philos->phargs->n_times_eat != -1) && ((int)philos->nteaten == philos->phargs->n_times_eat))
            break ;
    }
	return ((void *)(long)1);
}