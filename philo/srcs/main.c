/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:51:17 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 18:59:38 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	main(int ac, char **argv)
{
	t_data			data;

	if (ac != 5 && ac != 6)
	{
		printf("\033[48;5;57m%s\033[0;0m", ERRUSAGE);
		return (FAILURE);
	}
	else
	{
		if (check_input(ac, argv) == FAILURE)
		{
			printf("Wrong input. All arguments must be positive ints.\n");
			return (FAILURE);
		}
		else
		{
			init_simulation(&data, argv);
			create_threads(&data);
			if (data.nb_of_philos > 1)
				monitor_death(&data);
			join_threads(&data);
			end_simulation(&data);
		}
		
	}
	return (SUCCESS);
}