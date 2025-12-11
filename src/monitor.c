/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:43:26 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/11 20:33:50 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void *routine_monitor(void *arg)
{
    unsigned int    i;
    unsigned int    count;
    t_phargs        *phargs;

    phargs = (t_phargs *)arg;
    while (1)
    {
        count = 0;
        i = 0;
        while (i < phargs->n_philos)
        {
            if (phargs->philos[i].tlasteat >= phargs->time_die)
            {
                state_critical(phargs);
                //print_critical(&phargs->philos[i], "died");
                return ((void *)(uintptr_t)0);//why return 0? maybe return something useful to differentiate with philosophers finished eating and print when returning
            }
            if ((phargs->n_times_eat) != -1)
            {
                if (phargs->philos[i].nteaten == (unsigned int)phargs->n_times_eat)
                {
                    state_critical(phargs);
                    count ++;
                }
            }
            i ++;
        }
        if (count == phargs->n_philos)
        {
            printf("philosphers have finished eating\n");
            return ((void *)(uintptr_t)0);//why return 0?
        }
    }
    return ((void *)(uintptr_t)1);//why return 1?
}