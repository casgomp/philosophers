/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/06 13:44:47 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char **argv)
{
	t_phargs	phargs;

	if (argc < 5 || argc > 6)
		return (print_error_args(1), 1);
	if (!philo_init(&phargs, argv))
		return (1); //call cleanup function before returning.
	if (!create_threads(&phargs))
		return (1); //call cleanup function before returning.
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
	phargs->time_start = get_time_current();
	if (philo_init_philos(phargs) == 0)
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