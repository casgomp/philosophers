/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 20:24:52 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/11 20:33:42 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

void    state_critical(t_phargs *phargs)
{
    pthread_mutex_lock(&phargs->mutxstate);
    phargs->state = 1;
    pthread_mutex_unlock(&phargs->mutxstate);
}
