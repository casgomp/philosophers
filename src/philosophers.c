/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:57:38 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/06 13:44:49 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*routine_philo(void *arg)
{
    //unsigned int    i;
    t_phargs        *phargs;

    phargs = (t_phargs *)arg;
    /*i = 0;
    while (i < (unsigned int)phargs->n_times_eat)
    {
        (phargs->eaten[phargs->idx_philo].ntimes) ++;
        printf("philo %d has eaten %d times\n", phargs->idx_philo + 1, phargs->eaten[phargs->idx_philo].ntimes);
        i ++;
    }*/
    while (1)
    {
        pthread_mutex_lock(&phargs->mutex1);
        (phargs->eaten[phargs->idx_philo].ntimes) ++;
        printf("philo %d has eaten %d times\n", phargs->idx_philo + 1, phargs->eaten[phargs->idx_philo].ntimes);
        pthread_mutex_unlock(&phargs->mutex1);
        usleep(3000000);
    }
	return ((void *)(long)1);
}