/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 15:40:41 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/07 15:02:04 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void	end_simulation(t_data *data)
{
	pthread_mutex_destroy(&data->print);
	// pthread_mutex_destroy(&data->loop);
	free(data->philo_thr);
}