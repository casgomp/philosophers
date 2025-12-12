/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:50:52 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 19:57:22 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_phargs *phargs)
{
	unsigned int	i;

	i = 0;
	while (i < phargs->n_philos)
		pthread_mutex_destroy(&phargs->mutxfrk[i++]);
	pthread_mutex_destroy(&phargs->mutxstate);
	pthread_mutex_destroy(&phargs->mutxprint);
	if (phargs->philos)
		free(phargs->philos);
	if (phargs->mutxfrk)
		free(phargs->mutxfrk);
}
