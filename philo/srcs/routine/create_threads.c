/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:45:22 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 13:56:56 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

int	create_threads(t_data *data)
{
	t_philo	*philo_struct;
	int		i;

	i = 0;
	philo_struct = ft_calloc(data->nb_of_philos, sizeof(t_philo));
	data->philo_thr = ft_calloc(data->nb_of_philos, sizeof(pthread_t));
	while (i < data->nb_of_philos)
	{
		philo_struct[i] = init_one_philo(philo_struct[i], data, data->philo_thr[i], i);
		if (pthread_create(&data->philo_thr[i], NULL, &routine, &philo_struct[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
