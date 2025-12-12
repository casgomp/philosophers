/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:43:26 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 15:41:02 by pecastro         ###   ########.fr       */
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
            //if (t_since_meal >= phargs->time_die)
            if (t_since_meal >= phargs->time_die || check_state(&phargs->philos[0]) == 1)
            {
                state_critical(phargs);
                phargs->dead = phargs->philos[i].idxph;
                //print_critical(&phargs->philos[i], "died");
                return ((void *)(uintptr_t)2);//why return 0? maybe return something useful to differentiate with philosophers finished eating and print when returning
            }
            if ((phargs->n_times_eat) != -1)
            {
                if (phargs->philos[i].nteaten == (unsigned int)phargs->n_times_eat)
                    count ++;
            }
            i ++;
        }
        if (count == phargs->n_philos)
        {
            state_critical(phargs);
            //printf("philosphers have finished eating\n");
            return ((void *)(uintptr_t)3);//why return 0?
        }
        usleep(1000);
    }
    return ((void *)(uintptr_t)1);//why return 1?
}