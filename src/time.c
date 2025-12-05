/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:12:45 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/05 20:12:18 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_time_epoch(void)
{
    struct timeval  tv;
    unsigned int    time_epoch;

    if (gettimeofday(&tv, NULL) == -1)
        return (0); //perror
    time_epoch = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return ((int)time_epoch);
}

int get_time_current(void)
{
    struct timeval  tv;
    unsigned int    time_current;

    if (gettimeofday(&tv, NULL) == -1)
        return (0); //perror
    time_current = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - get_time_epoch();
    return ((int)time_current);
}