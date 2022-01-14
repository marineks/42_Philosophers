/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:45:22 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 19:30:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

int	create_threads(t_data *data)
{
	t_philo	*philo_struct;
	int		i;

	i = 0;
	philo_struct = ft_calloc(data->nb_of_philos, sizeof(t_philo));
	if (!philo_struct)
		return (FAILURE);
	data->philo_thr = ft_calloc(data->nb_of_philos, sizeof(pthread_t));
	if (!data->philo_thr)
		return (FAILURE);
	while (i < data->nb_of_philos)
	{
		philo_struct[i] = init_one_philo(philo_struct[i],\
		data, data->philo_thr[i], i);
		if (pthread_create(&data->philo_thr[i], NULL, &routine,\
		&philo_struct[i]) != SUCCESS)
			return (FAILURE);
		i++;
	}
	data->philo = philo_struct;
	return (SUCCESS);
}
