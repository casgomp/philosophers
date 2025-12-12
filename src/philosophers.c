/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:57:38 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 15:45:38 by pecastro         ###   ########.fr       */
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
        //if (check_state(philos) == 1)
        if (philos->phargs->state == 1)
            return ((void *)(long)0);
        print_critical(philos, "is thinking");
        usleep(1000);
        //if (check_state(philos) == 1)
        if (philos->phargs->state == 1)
            return ((void *)(long)0);
        pthread_mutex_lock(fork_low);
        print_critical(philos, "has taken a fork");
        if (philos->phargs->n_philos == 1)
            state_critical(philos->phargs);
        //if (check_state(philos) == 1)
        if (philos->phargs->state == 1)
            return (pthread_mutex_unlock(fork_low), (void *)(long)0);
        pthread_mutex_lock(fork_high);
        print_critical(philos, "has taken a fork");
        //if (check_state(philos) == 1)
        if (philos->phargs->state == 1)
            return (pthread_mutex_unlock(fork_high), pthread_mutex_unlock(fork_low), (void *)(long)0);
        print_critical(philos, "is eating");
        philos->tlasteat = get_time_relative(philos->phargs);
        usleep(philos->phargs->time_eat * 1000);
        (philos->nteaten) ++;
        //printf("philo %d has eaten %d times\n", idx + 1, philos->nteaten); //this printf statement is not part of the assignment.
        
        pthread_mutex_unlock(fork_high);
        pthread_mutex_unlock(fork_low);
        
        if (check_state(philos) == 1)
            return ((void *)(long)0);
        print_critical(philos, "is sleeping");
        usleep(philos->phargs->time_sleep * 1000);

        /*if ((philos->phargs->n_times_eat != -1) && ((int)philos->nteaten == philos->phargs->n_times_eat))
            break ;*/
        
        /*pthread_mutex_lock(&philos->phargs->mutxstate);
        if (philos->phargs->state == 1)
            return (pthread_mutex_unlock(&philos->phargs->mutxstate), (void *)(long)1);
        pthread_mutex_unlock(&philos->phargs->mutxstate);*/
    }
	return ((void *)(long)1);
}