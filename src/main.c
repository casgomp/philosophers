/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 15:24:48 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char **argv)
{
	t_phargs	phargs;

	if (argc < 5 || argc > 6)
		return (print_error_args(), 1);
	if (!philo_init(&phargs, argv))
		return (1); //call cleanup function before returning.
	if (phargs.n_philos <= 0)
		return (print_error_args(), 1); //call cleanup function before returning.
	if (!create_threads(&phargs))
		return (1); //call cleanup function before returning.//
	//cleanup function
	return (0);
}

int	philo_init(t_phargs *phargs, char **argv)
{
	if (!philo_init_atoi(argv[1], &(phargs->n_philos)))
		return (0);
	if (!philo_init_atoi(argv[2], &(phargs->time_die)))
		return (0);
	if (!philo_init_atoi(argv[3], &(phargs->time_eat)))
		return (0);
	if (!philo_init_atoi(argv[4], &(phargs->time_sleep)))
		return (0);
	phargs->n_times_eat = -1;
	if (argv[5] && !philo_init_atoi(argv[5], (unsigned int *)&(phargs->n_times_eat)))
		return (0);
	phargs->time_start = get_time_absolute();
	phargs->state = 0;
	if (philo_init_philos(phargs) == 0)
		return (0);
	if (philo_init_mutxs(phargs) == 0)
		return (0);
	if (pthread_mutex_init(&phargs->mutxstate, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&phargs->mutxprint, NULL) != 0)
		return (0);
	return (1);
}

int	philo_init_philos(t_phargs *phargs)
{
	phargs->philos = malloc(sizeof(t_philo) * phargs->n_philos);
	if (!phargs->philos)
		return (0);
	memset(phargs->philos, 0, sizeof(t_philo) * phargs->n_philos);
	return (1);
}

int	philo_init_mutxs(t_phargs *phargs)
{
	unsigned int i;

	phargs->mutxfrk = malloc(sizeof(pthread_mutex_t) * phargs->n_philos);
	if (!phargs->mutxfrk)
		return (0);
	i = 0;
	while (i < phargs->n_philos)
	{
		if (pthread_mutex_init(&phargs->mutxfrk[i], NULL) != 0)
		{
			while (i > 0)
			{
				i --;
				pthread_mutex_destroy(&phargs->mutxfrk[i]);
			}
			free (phargs->mutxfrk);
			return (0);
		}
		i ++;
	}
	return (1);
}