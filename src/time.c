/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:12:45 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/12 19:42:17 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time_absolute(void)
{
	struct timeval	tv;
	unsigned int	time_epoch;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	time_epoch = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return ((int)time_epoch);
}

int	get_time_relative(t_phargs *phargs)
{
	unsigned int	time_absolute;
	unsigned int	time_relative;

	time_absolute = get_time_absolute();
	time_relative = time_absolute - phargs->time_start;
	return ((int)time_relative);
}
