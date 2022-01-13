/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:05:35 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 17:29:06 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

/*
**	Après avoir mangé et dormi, le philosophe doit penser tant qu'il n'a pas
**  deux fourchettes pour remanger 
*/
void	make_philo_think(t_philo *philo)
{
	print_status(philo, "is thinking 🤔", YELLOW);
}
