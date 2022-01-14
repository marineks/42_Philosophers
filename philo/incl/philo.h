/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msanjuan <msanjuan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 18:52:39 by msanjuan          #+#    #+#             */
/*   Updated: 2022/01/14 17:58:27 by msanjuan         ###   ########.fr       */
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
# define GREEN "\033[0;32m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[0;36m"
# define RED "\033[4;31m"
# define RESET "\033[0m"
# define ERRUSAGE "Correct usage is : \
	./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> \
	[number_of_times_each_philosopher_must_eat]\n"


/*
**	STRUCTURES
*/

typedef struct s_data
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_times_must_eat;
	int				total_meal;
	int				count_meals;
	pthread_t		*philo_thr;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	last_meal;
	pthread_mutex_t	all_meals;
	long int		start_time;
	_Bool			someone_died;
	_Bool			option_on;
	struct s_philo	*philo;

}				t_data;

typedef struct s_philo
{
	t_data			*data;
	pthread_t		thread;
	_Bool			is_dead;
	int				id;
	int				nb_meals_to_eat;
	long int		last_meal_eaten;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}				t_philo;

/*
**		SRCS
*/
void				init_simulation(t_data *data, char **argv);
void				init_forks(t_data *data);
pthread_mutex_t		*attribute_forks(t_data *data, char fork, int i);
int					create_threads(t_data *data);
t_philo				init_one_philo(t_philo philo, t_data *data, pthread_t philo_thr, int i);
int					join_threads(t_data *data);

void				*routine();
void				manage_one_philo(t_philo *philo);
void				end_simulation(t_data *data);
void				stop_simulation(t_philo *philo);

void				make_philo_think(t_philo *philo);
void				make_philo_sleep(t_philo *philo);
void				make_philo_eat(t_philo *philo);

int					monitor_death(t_data *data);
int					is_alive(t_philo *philo);
/*
**		UTILS
*/
long int			get_time(void);
void				print_status(t_philo *philo, char *str, char *color);
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_calloc(size_t count, size_t size);

#endif