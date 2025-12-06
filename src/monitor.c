/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:43:26 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/06 13:44:49 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void *routine_monitor(void *arg)
{
    unsigned int    i;
    unsigned int    count;
    t_phargs        *phargs;
    static          pthread_mutex_init;

    phargs = (t_phargs *)arg;
    while (1)
    {
        count = 0;
        i = 0;
        while (i < phargs->n_philos)
        {
            if (phargs->eaten[i].time_last_eat >= phargs->time_die)
                return ((void *)(uintptr_t)0);
            if ((phargs->n_times_eat) != -1)
            {
                if (phargs->eaten[i].ntimes == (unsigned int)phargs->n_times_eat)
                    count ++;
            }
            i ++;
        }
        if (count == phargs->n_philos)
        {
            printf("philosphers have finished eating\n");
            return ((void *)(uintptr_t)0);
        }
    }
    /*while (1)
    {
        if (phargs->eaten[i].time_last_eat >= phargs->time_die)
            return ((void *)(uintptr_t)0);
        if (phargs->n_times_eat != -1)
        {
            count = 0;
            i = 0;
            while (phargs->philo[i])
            {
                if ((phargs->eaten)[i].ntimes == (unsigned int)phargs->n_times_eat)
                    count ++;
                i ++;
            }
            if (count == phargs->n_philos)
                return ((void *)(uintptr_t)0);
        }
    }*/
    return ((void *)(uintptr_t)1);
}