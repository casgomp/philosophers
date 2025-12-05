/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/05 20:12:12 by pecastro         ###   ########.fr       */
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
	phargs->n_philos = philo_init_atoi(argv[1]);
	if (!phargs->n_philos)
		return (0);
	phargs->time_die = philo_init_atoi(argv[2]);
	if (!phargs->time_die)
		return (0);
	phargs->time_eat = philo_init_atoi(argv[3]);
	if (!phargs->time_eat)
		return (0);
	phargs->time_sleep = philo_init_atoi(argv[4]);
	if (!phargs->time_sleep)
		return (0);
	phargs->n_times_eat = -1;
	if (argv[5])
	{
		phargs->n_times_eat = philo_init_atoi(argv[5]);
		if (!phargs->n_times_eat)
			return (0);
	}
	phargs->time_start = get_time_current();
	phargs->eaten = malloc(sizeof(t_eat) * phargs->n_philos);
	if (!phargs->eaten)
		return (0);
	memset(phargs->eaten, 0, sizeof(*phargs->eaten));
	return (1);
}

int	philo_init_atoi(char *arg)
{
	unsigned int	nbr;
	int				error;

	error = 0;
	nbr = ft_atoi_safe(arg, &error);
	if (!nbr && error == 1)
		return (0);
	return ((int)nbr);
}