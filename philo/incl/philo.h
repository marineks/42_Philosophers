/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:52:39 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/03 17:01:43 by msanjuan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>

# define SUCCESS 0
# define FAILURE -1
# define ERRUSAGE "Correct usage is : \
	./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
	[number_of_times_each_philosopher_must_eat]\n"


/*
**	STRUCTURES
*/
typedef struct s_philo
{
	pthread_t		philo_thread;
	pthread_mutex_t	*forks;
	_Bool			is_dead;
	_Bool			has_eaten;
	_Bool			has_slept;
	_Bool			has_thought;
	int				id;
	
}				t_philo;

typedef struct s_data
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_must_eat;
	pthread_t		*philo;
	pthread_mutex_t	mutex;
	long			elapsed_time;

}				t_data;

/*
**		SRCS
*/
void		init_simulation(t_data *data, char **argv);
int			create_threads(t_data *data);

void		*routine();
long int	get_time(struct timeval time);
void		end_simulation(t_data *data);
void		stop_simulation(t_data *data, t_philo *philo);

void		make_philo_think(t_philo *philo);
void		make_philo_sleep(t_philo *philo, t_data *data);
void		reset_status(t_philo *philo);
/*
**		UTILS
*/
int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);

#endif