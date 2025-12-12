/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:43:26 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 18:42:33 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void *routine_monitor(void *arg)
{
    unsigned int    i;
    unsigned int    count;
    unsigned int    t_since_meal;
    t_phargs        *phargs;

    phargs = (t_phargs *)arg;
    while (1)
    {
        count = 0;
        i = 0;
        while (i < phargs->n_philos)
        {
            t_since_meal = get_time_relative(phargs) - phargs->philos[i].tlasteat;
            if (t_since_meal >= phargs->time_die || phargs->state == 1)
                return (state_critical(phargs), phargs->dead = phargs->philos[i].idxph, (void *)(uintptr_t)2);
            if ((phargs->n_times_eat != -1) && (phargs->philos[i].nteaten >= (unsigned int)phargs->n_times_eat))
                count ++;
            i ++;
        }
        if (count == phargs->n_philos)
            return (state_critical(phargs), (void *)(uintptr_t)3);
        usleep(1000);
    }
    return ((void *)(uintptr_t)1);
}