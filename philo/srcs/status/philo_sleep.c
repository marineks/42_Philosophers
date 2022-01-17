/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:27 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/17 14:05:56 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
** This function :
**	- Prints on the terminal what the philosopher is doing
**	- Makes one philosopher sleep for <time_to_sleep> milliseconds;
*/
void	make_philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping 😪", BLUE);
	usleep(philo->data->time_to_sleep * 1000);
}
