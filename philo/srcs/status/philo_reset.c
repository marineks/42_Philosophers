/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:46:48 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/12 18:30:14 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	When a loop is completed, this function resets all the actions a philosopher
**	can make to "false".
*/
void	reset_status(t_philo *philo)
{
	philo->has_eaten = false;
	philo->has_slept = false;
	philo->has_thought = false;
}