/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:53:22 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 19:02:39 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_phargs *phargs)
{
	unsigned int	i;
	void			*retval_mo;
	void			*retval_ph;

	create_threads_init_philos(phargs);
	if (pthread_create((&phargs->monitor), NULL, &routine_monitor, phargs) != 0)
		return (perror("Failed to create thread"), 0);
	i = 0;
	while (i < phargs->n_philos)
	{
		if (pthread_create(&(phargs->philos[i].thrph), 
				NULL, &routine_philo, &phargs->philos[i]) != 0)
			return (perror("Failed to create thread"), 0);
		i ++;
	}
	pthread_join(phargs->monitor, (void **)&retval_mo);
	print_end_simulation(phargs, retval_mo);
	i = 0;
	while (i < phargs->n_philos)
	{
		pthread_join(phargs->philos[i].thrph, (void **)&retval_ph);
		i ++;
	}
	return (1);
}

void	create_threads_init_philos(t_phargs *phargs)
{
	unsigned int	i;

	i = 0;
	while (i < phargs->n_philos)
	{
		(phargs->philos[i]).phargs = phargs;
		phargs->philos[i].idxph = i;
		phargs->philos[i].tlasteat = 0;
		phargs->philos[i].nteaten = 0;
		i ++;
	}
}
