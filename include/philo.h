/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:03:56 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 18:40:43 by pecastro         ###   ########.fr       */
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

typedef struct s_phargs t_phargs;

typedef struct  s_philo
{
    pthread_t               thrph;
    unsigned int            idxph;
    _Atomic unsigned int    tlasteat;
    _Atomic unsigned int    nteaten;
    t_phargs                *phargs;
}   t_philo;

typedef struct s_phargs {
    unsigned int            n_philos;
    unsigned int            time_die;
    unsigned int            time_eat;
    unsigned int            time_sleep;
    int                     n_times_eat;
    unsigned int            time_start;
    _Atomic unsigned int    state;
    unsigned int            dead;
    t_philo                 *philos;
    pthread_t               monitor;
    pthread_mutex_t         *mutxfrk;
    pthread_mutex_t         mutxstate;
    pthread_mutex_t         mutxprint;
}   t_phargs ;

int             main(int argc, char **argv);
int             philo_init(t_phargs *phargs, char **argv);
int	            philo_init_philos(t_phargs *phargs);
int	            philo_init_mutxs(t_phargs *phargs);

int             create_threads(t_phargs *phargs);
void	        create_threads_init_philos(t_phargs *phargs);

void            *routine_monitor(void *arg);

void            *routine_philo(void *arg);
unsigned int    routine_philo_loop(t_philo *philos, pthread_mutex_t *fork_low, pthread_mutex_t *fork_high);
unsigned int    philo_has_two_forks(t_philo *philos, pthread_mutex_t *fork_low, pthread_mutex_t *fork_high);

int             get_time_absolute(void);
int             get_time_relative(t_phargs *phargs);

int	            philo_init_atoi(char *arg, unsigned int *dest);
int	            ft_atoi_safe(const char *nptr, int *error);
unsigned int	ft_atoi_safe_digit(const char *nptr, int i, int *error, int sign);

void            print_error_args(void);
void            print_critical(t_philo *philos, char *str);
void            state_critical(t_phargs *phargs);
int             check_state(t_philo *philos);
void	        print_end_simulation(t_phargs *phargs, void *retval);

void            cleanup(t_phargs *phargs);

#endif