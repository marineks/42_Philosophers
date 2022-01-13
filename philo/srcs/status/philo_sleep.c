/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:27 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 17:28:44 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
** This function :
**	- Makes one philosopher sleep for <time_to_sleep> milliseconds;
**	- Usleep * 1000 to convert in milliseconds;
**	- Displays the time with the corresponding philo;
**	- Set the bool "has slept" to true.
**	- Use of a mutex to prevent data race
*/
void	make_philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping 😪", BLUE);
	// philo->has_slept = true;
	usleep(philo->data->time_to_sleep * 1000);
}