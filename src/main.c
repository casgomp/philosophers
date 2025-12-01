/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/01 17:37:38 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char **argv)
{
	unsigned int	time_start;

	if (argc < 5 || argc > 6)
		return (print_error_args(1), 1);

	time_start = get_time();
	printf("time_start = %d\n", time_start);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	usleep(1000);
	time_start = get_time();
	printf("time_start = %d\n", time_start);
	usleep(1000);
	time_start = get_time();
	printf("time_start = %d\n", time_start);

	if (!philo_init(argv))
		return (1);

	//cleanup function
	return (0);
}

void	*routine()
{
	printf("thread \n");
	return ((void *) 1);//temp solution, shouldn't be here.
}

int	create_threads(t_phargs *phargs)
{
	unsigned int	i;

	phargs->philo = malloc(sizeof(pthread_t) * phargs->n_philos);
	if (!phargs->philo)
		return (0);
	i = 0;
	while (i < phargs->n_philos)
	{
		if (pthread_create((phargs->philo + i), NULL, &routine,  NULL) != 0)
			return (perror("Failed to create thread"), 0);
		printf("philosopher %d has started\n", i + 1);
		i ++;
	}
	i = 0;
	while (i < phargs->n_philos)
	{
		if (pthread_join(phargs->philo[i], NULL) != 0)
			return (0);
		printf("philosopher %d has finished execution\n", i + 1);
		i ++;
	}
	return (1);
}

int	philo_init(char **argv)
{
	t_phargs	phargs;

	phargs.n_philos = atoi(argv[1]); //libft and atoi not allowed, so add atoi_protect inside philo project.
	if (!phargs.n_philos)
		return (0);
	phargs.time_die = atoi(argv[2]);
	if (!phargs.time_die)
		return (0);
	phargs.time_eat = atoi(argv[3]);	
	if (!phargs.time_eat)
		return (0);
	phargs.time_sleep = atoi(argv[4]);
	if (!phargs.time_sleep)
		return (0);
	if (argv[5])
	{
		phargs.n_times_eat = atoi(argv[5]);
		if (!phargs.n_times_eat)
			return (0);
	}
	if (!create_threads(&phargs))
		return (0);
	return (1);
}

void print_error_args(int n)
{
	char	**msg;

	msg = NULL;
	if (n == 1)
	{
		msg = malloc(sizeof(char *) * 7);
		if (!msg)
			return;
		msg[0] = "Input ./executable + the following options:";
		msg[1] = "1) number_of_philosophers";
		msg[2] = "2) time_to_die (in milliseconds)";
		msg[3] = "3) time_to_eat (in milliseconds)";
		msg[4] = "4) time_to_sleep (in milliseconds)";
		msg[5] = "5) number_of_times_each_philosopher_must_eat (optional argument)";
		printf("%s\n%s\n%s\n%s\n%s\n%s\n",msg[0],msg[1],msg[2],msg[3],msg[4],msg[5]);
	}
	free (msg);
}
