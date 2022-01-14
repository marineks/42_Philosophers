/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:51:17 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/13 19:00:02 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	main(int ac, char **argv)
{
	t_data			data;

	if (ac != 5 && ac != 6)
	{
		printf("\033[48;5;57m%s\033[0;0m", ERRUSAGE);
		exit(1);
	}
	else
	{
		init_simulation(&data, argv);
		create_threads(&data);
		monitor_death(&data);
		// printf("ET CEST LA MORT, QUI T'A ASSASSINEE, MARCIAAAAAA\n");
		join_threads(&data);
		end_simulation(&data);
	}
	return (SUCCESS);
}