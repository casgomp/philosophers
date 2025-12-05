/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 16:57:38 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/05 20:12:17 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*routine_philo(void *arg)
{
    unsigned int    i;
    t_phargs        *phargs;

    phargs = (t_phargs *)arg;
	printf("thread\n");
    while (1)
    {
        i = 0;
        while (i < phargs->n_philos)
        {
            (*(phargs->eaten[i].ntimes)) ++;
            i ++;
        }
    }
	return ((void *)(long)1);
}
