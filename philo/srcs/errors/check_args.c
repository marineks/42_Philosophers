/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:03:50 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 18:35:01 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

int	check_input(int ac, char **args)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_is_digit(args[i]) == FAILURE || ft_atoi(args[i]) < 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}