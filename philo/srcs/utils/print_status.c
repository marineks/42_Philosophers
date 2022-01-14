/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:58:21 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 19:37:34 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"


void	print_status(t_philo *philo, char *str, char *color)
{
	if (is_alive(philo) == SUCCESS)
	{
		pthread_mutex_lock(&philo->data->print);
		printf("%s%ld ms \t | %d %s\n%s", color,\
		 (get_time() - philo->data->start_time), philo->id + 1, str, RESET);
		pthread_mutex_unlock(&philo->data->print);
	}
}