/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:12:45 by pecastro          #+#    #+#             */
/*   Updated: 2025/11/17 17:16:26 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_time(void)
{
    struct timeval tv;

    if (gettimeofday(&tv, NULL) == -1)
         return (0);
    return (((int)tv.tv_usec)/1000);
}
