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
    t_philo        *philos;
    unsigned int    idx;

    philos = (t_philo *)arg;
    while (1)
    {
        pthread_mutex_lock(&philos->phargs->mutex1);
        idx = philos->idxph;
        printf("idx = %d. philosopher number= %d\n", idx, idx + 1);
        (philos->ntimeeat) ++;
        printf("philo %d has eaten %d times\n", idx + 1, philos->ntimeeat);
        pthread_mutex_unlock(&philos->phargs->mutex1);
        usleep(3000000);
    }
	return ((void *)(long)1);
}