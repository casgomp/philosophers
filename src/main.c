/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 11:59:23 by pecastro          #+#    #+#             */
/*   Updated: 2025/11/17 17:23:45 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	unsigned int	time_start;

	if (argc < 5)
		return (print_error_args(1), 1);
	(void)argv;

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

	return (0);
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
