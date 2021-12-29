/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:51:17 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/29 19:20:24 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

void* routine() // void * et on caste apres
{
	printf("Test \n");
	sleep(3);
	printf("Ending thread\n");
	return (SUCCESS);
}

int	main(int ac, char **argv)
{
	(void)ac;
	(void)argv;
	pthread_t philo, philo2; // create a struc storing the info about the thread

	if (pthread_create(&philo, NULL, &routine, NULL) != SUCCESS)
		return (FAILURE);
	if (pthread_create(&philo2, NULL, &routine, NULL) !!= SUCCESS)
		return (FAILURE);
	pthread_join(philo, NULL); // = the wait for threads
	pthread_join(philo2, NULL);
	return (0);
}