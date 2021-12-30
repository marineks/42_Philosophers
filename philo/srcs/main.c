/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:51:17 by msanjuan          #+#    #+#             */
/*   Updated: 2021/12/30 14:48:21 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

pthread_mutex_t mutex;

void* routine() // void * et on caste apres
{
	pthread_mutex_lock(&mutex);
	printf("Test \n");
	// sleep(3);
	// printf("Ending thread\n");
	pthread_mutex_unlock(&mutex);
	return (SUCCESS);
}

int	main(int ac, char **argv)
{
	(void)ac;
	(void)argv;
	pthread_t philo, philo2; // create a struc storing the info about the thread
	

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&philo, NULL, &routine, NULL) != SUCCESS)
		return (FAILURE);
	if (pthread_create(&philo2, NULL, &routine, NULL) != SUCCESS)
		return (FAILURE);
	pthread_join(philo, NULL); // = the wait for threads
	pthread_join(philo2, NULL);
	pthread_mutex_destroy(&mutex);
	return (0);
}