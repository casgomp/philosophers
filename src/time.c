/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pecastro <pecastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:12:45 by pecastro          #+#    #+#             */
/*   Updated: 2025/12/01 17:37:35 by pecastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_time(void) //probably better have two functions. one for start one for current.
{
    struct timeval  tv;
    unsigned int    time_start; //can ad to struct: thn if struct->timestart == -1 store_time_start, else subtract current.

    if (gettimeofday(&tv, NULL) == -1)
        return (0); //perror
    if (time_start == -1) //must initialize that var at beginning in main to -1.
        time_start = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    else
        current_time = ((tv.tv_sec * 1000) + (tv.tv_usec / 1000)) - time_start;
    
    return (((int)tv.tv_usec)/1000); //dont return, just store in struct.
}
