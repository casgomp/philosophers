/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:53:22 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/05 20:12:14 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	create_threads(t_phargs *phargs)
{
	unsigned int	i;
    void            *retval;

    if (pthread_create((&phargs->monitor), NULL, &routine_monitor, phargs) != 0)
		return (perror("Failed to create thread"), 0);
    printf("monitor has started\n");
	phargs->philo = malloc(sizeof(pthread_t) * phargs->n_philos);
	if (!phargs->philo)
		return (0);
	i = 0;
	while (i < phargs->n_philos)
	{
		if (pthread_create((phargs->philo + i), NULL, &routine_philo, phargs) != 0)
			return (perror("Failed to create thread"), 0);
		printf("philosopher %d has started\n", i + 1);
		i ++;
	}
    if (pthread_join(phargs->monitor, (void **)&retval) != 0 || (uintptr_t)retval == 0)
		return (0); //casting to (void **) is not required in c i.e. in (void **)&retval?
    printf("monitor has finished execution\n");
	i = 0;
	while (i < phargs->n_philos)
	{
		if (pthread_join(phargs->philo[i], (void **)&retval) != 0 || (uintptr_t)retval == 0)
			return (0);
		printf("philosopher %d has finished execution\n", i + 1);
		i ++;
	}
	return (1);
}
