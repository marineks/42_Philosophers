/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:58:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 17:41:19 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"


void	print_status(t_philo *philo, char *str, char *color)
{
	
	pthread_mutex_lock(&philo->data->print);
	printf("%s%ld ms | %d %s\n%s", 
		color, (get_time() - philo->data->start_time), philo->id + 1, str, RESET);
	pthread_mutex_unlock(&philo->data->print);
}