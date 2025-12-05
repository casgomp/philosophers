/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:03:56 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/05 20:12:19 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

typedef struct s_eat
{
    unsigned int    *time_last_eat;
    unsigned int    *ntimes;
}   t_eat;

typedef struct s_phargs {
    unsigned int    n_philos;
    unsigned int    time_die;
    unsigned int    time_eat;
    unsigned int    time_sleep;
    int             n_times_eat;
    unsigned int    time_start;
    t_eat           *eaten;
    pthread_t       *philo;
    pthread_t       monitor;
}   t_phargs ;

int             main(int argc, char **argv);
int             philo_init(t_phargs *phargs, char **argv);
int             philo_init_atoi(char *arg);

int             create_threads(t_phargs *phargs);

void            *routine_monitor();

void            *routine_philo();

int             monitor(t_phargs *phargs);

int             get_time_epoch(void);
int             get_time_current(void);

int	            ft_atoi_safe(const char *nptr, int *error);
unsigned int	ft_atoi_safe_digit(const char *nptr, int i, int *error, int sign);
void            print_error_args(int n);

#endif
