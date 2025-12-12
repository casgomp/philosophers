/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:57:38 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 18:42:36 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*routine_philo(void *arg)
{
    t_philo         *philos;
    unsigned int    left_fork_idx;
    unsigned int    right_fork_idx;
    pthread_mutex_t *fork_low;
    pthread_mutex_t *fork_high;

    philos = (t_philo *)arg;
    left_fork_idx = philos->idxph;
    right_fork_idx = (philos->idxph + 1) % philos->phargs->n_philos;
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
    if (!routine_philo_loop(philos, fork_low, fork_high))
        return ((void *)(long)0);
    return ((void *)(long)1);
}

unsigned int routine_philo_loop(t_philo *philos, pthread_mutex_t *fork_low, pthread_mutex_t *fork_high)
{
    while (1)
    {
        if (philos->phargs->state == 1)
            return (0);
        print_critical(philos, "is thinking");
        usleep(1000);
        if (philos->phargs->state == 1)
            return (0);
        pthread_mutex_lock(fork_low);
        print_critical(philos, "has taken a fork");
        if (philos->phargs->n_philos == 1)
            state_critical(philos->phargs);
        if (check_state(philos) == 1)
            return (pthread_mutex_unlock(fork_low), 0);
        pthread_mutex_lock(fork_high);
        print_critical(philos, "has taken a fork");
        if (philos->phargs->state == 1)
            return (pthread_mutex_unlock(fork_high), pthread_mutex_unlock(fork_low), 0);
        if (!philo_has_two_forks(philos, fork_high, fork_low))
            return (0);
    }
    return (1);
}

unsigned int    philo_has_two_forks(t_philo *philos, pthread_mutex_t *fork_low, pthread_mutex_t *fork_high)
{
    philos->tlasteat = get_time_relative(philos->phargs);
    usleep(philos->phargs->time_eat * 1000);
    (philos->nteaten) ++;
    pthread_mutex_unlock(fork_high);
    pthread_mutex_unlock(fork_low);
    if (philos->phargs->state == 1)
        return (0);
    print_critical(philos, "is sleeping");
    usleep(philos->phargs->time_sleep * 1000);
    return (1);
}