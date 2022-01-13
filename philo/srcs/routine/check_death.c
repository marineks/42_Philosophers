/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:43:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 17:24:37 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

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
		if (data->someone_died == true)
			return (FAILURE);
		// i++;
		// if (i == data->nb_of_philos)
		// 	i = 0;
	}
	return (SUCCESS);
}