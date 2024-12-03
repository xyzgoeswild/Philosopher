/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:30:02 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/12/03 03:38:51 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int dead_check(t_philo *philo)
{
    pthread_mutex_lock(philo->dead_lock);
    if (*philo->dead == 1)
        return (pthread_mutex_unlock(philo->dead_lock), 1);
    pthread_mutex_unlock(philo->dead_lock);
    return (0);
}

void    *philo_routine(void *ptr)
{
    t_philo *philo;

    philo = (t_philo *)ptr;
    if (philo->id % 2 == 0)
        ft_usleep(1);
    while (1)
    {
        eat(philo);
        sleep(philo);
        print_status(philo, "is thinking");
    }
    return (ptr);
}

int create_threads(t_program *program, pthread_mutex_t *forks)
{
    int	i;

    i = 0;
    program->philos[0].start_time = get_time();
    while (i < program->philos[0].num_of_philos)
    {
        if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
                &program->philos[i]))
            return (write(2, "\033[31mError creating thread\n", 27), 1);
        i++;
    }
    i = 0;
    while (i < program->philos[0].num_of_philos)
    {
        if (pthread_join(program->philos[i].thread, NULL))
            return (write(2, "\033[31mError joining thread\n", 26), 1);
        i++;
    }
    return (0);
}