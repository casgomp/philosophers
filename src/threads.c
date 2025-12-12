/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:53:22 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 14:27:34 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	create_threads(t_phargs *phargs)
{
	unsigned int	i;
    void            *retval_mo;
	void            *retval_ph;

	i = 0;
	while (i < phargs->n_philos)
	{
		(phargs->philos[i]).phargs = phargs;
		phargs->philos[i].idxph = i;
		phargs->philos[i].tlasteat = 0;
		phargs->philos[i].nteaten = 0;
		i ++;
	}
    if (pthread_create((&phargs->monitor), NULL, &routine_monitor, phargs) != 0)
		return (perror("Failed to create thread"), 0);
    //printf("monitor has started\n");
	i = 0;
	while (i < phargs->n_philos)
	{
		if (pthread_create(&(phargs->philos[i].thrph), NULL, &routine_philo, &phargs->philos[i]) != 0)
			return (perror("Failed to create thread"), 0);
		//printf("philosopher %d has started\n", i + 1);
		i ++;
	}
    /*if (pthread_join(phargs->monitor, (void **)&retval) != 0 || (uintptr_t)retval == 0)
		return (0);*/
	pthread_join(phargs->monitor, (void **)&retval_mo);
	print_end_simulation(phargs, retval_mo);
    //printf("monitor has finished execution\n");
	i = 0;
	while (i < phargs->n_philos)
	{
		/*if (pthread_join(phargs->philos[i].thrph, (void **)&retval) != 0 || (uintptr_t)retval == 0)
			return (0);*/
		pthread_join(phargs->philos[i].thrph, (void **)&retval_ph);
		//printf("philosopher %d has finished execution\n", i + 1);
		i ++;
	}
	//pthread_mutex_destroy(&phargs->mutex1); ...no need? destroy in cleanup function
	return (1);
}
