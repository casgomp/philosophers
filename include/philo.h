/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:03:56 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/02 18:10:06 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_phargs {
    unsigned int    n_philos;
    unsigned int    time_die;
    unsigned int    time_eat;
    unsigned int    time_sleep;
    unsigned int    n_times_eat;
    pthread_t       *philo;
    pthread_t       monitor;
}   t_phargs ;

void print_error_args(int n);
void	*routine();
int	create_threads(t_phargs *phargs);
int	philo_init(char **argv);
int get_time(void);

#endif
