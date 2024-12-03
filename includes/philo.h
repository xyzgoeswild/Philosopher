/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 23:34:40 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/12/03 03:38:52 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define PHILO_MAX 300
# define RESET_COLOR "\033[0m"
# define RED_COLOR "\033[31m"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;
typedef struct s_program
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_program;

/* main.c */
int					check_arg_content(char *arg);
int					check_args(char **argv);
void				destory_all(char *str, t_program *program,
						pthread_mutex_t *forks);

/* initialize.c */
void				load_program(t_program *program, t_philo *philos);
void				load_forks(pthread_mutex_t *forks, int philo_num);
void				load_philos(t_philo *philos, t_program *program,
						pthread_mutex_t *forks, char **argv);
void				load_input(t_philo *philo, char **argv);

/* threads.c */
int					thread_create(t_program *program, pthread_mutex_t *forks);
void				*monitor(void *pointer);
void				*philo_routine(void *pointer);

/* actions.c */
void				eat(t_philo *philo);
void				sleep(t_philo *philo);
void				think(t_philo *philo);

/* monitor.c */
int					dead_loop(t_philo *philo);
int					check_if_all_ate(t_philo *philos);
int					check_if_dead(t_philo *philos);
int					philosopher_dead(t_philo *philo, size_t time_to_die);

/* utils.c */
int					ft_atoi(const char *str);
int					ft_usleep(size_t microseconds);
int					ft_strlen(char *str);
void				print_message(char *str, t_philo *philo, int id);
size_t				get_current_time(void);

#endif
