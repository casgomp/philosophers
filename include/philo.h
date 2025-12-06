/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:03:56 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/06 13:44:47 by pecastro         ###   ########.fr       */
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

/*typedef struct s_eat
{
    unsigned int    tlast;
    unsigned int    ntimes;
}   t_eat;*/

typedef struct s_phargs t_phargs;

typedef struct  s_philo
{
    pthread_t       thrph;
    unsigned int    idxph;
    unsigned int    tlasteat;
    unsigned int    ntimeeat;
    t_phargs        *phargs;
}   t_philo;

typedef struct s_phargs {
    unsigned int    n_philos;
    unsigned int    time_die;
    unsigned int    time_eat;
    unsigned int    time_sleep;
    int             n_times_eat;
    unsigned int    time_start;
    t_philo         *philos;
    pthread_t       monitor;
    pthread_mutex_t mutex1; //do separate struct containing various mutexes?
}   t_phargs ;

int             main(int argc, char **argv);
int             philo_init(t_phargs *phargs, char **argv);
int	            philo_init_philos(t_phargs *phargs);

int             create_threads(t_phargs *phargs);

void            *routine_monitor(void *arg);

void            *routine_philo(void *arg);

int             get_time_epoch(void);
int             get_time_current(void);

int	            philo_init_atoi(char *arg, unsigned int *dest);
int	            ft_atoi_safe(const char *nptr, int *error);
unsigned int	ft_atoi_safe_digit(const char *nptr, int i, int *error, int sign);
void            print_error_args(int n);

#endif
