/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:43:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 18:12:07 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

void	check_time_of_death(t_philo *philo)
{
	long int	current;

	current = get_time();
	if (current - philo->last_meal_eaten > philo->data->time_to_die)
		philo->data->someone_died = true;
}
/*
*	As the philosophers are not allowed to communicate with each other,
*	we must check the eventuality of their death in the main thread.
*/
int	monitor_death(t_data *data)
{
	// int	i;

	// i = 0;
	
	while (1)
	{
		check_time_of_death(philo) // data // philo // i
		if (data->someone_died == true)
			return (FAILURE);
		// i++;
		// if (i == data->nb_of_philos)
		// 	i = 0;
	}
	return (SUCCESS);
}