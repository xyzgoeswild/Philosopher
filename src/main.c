/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amuhsen- <amuhsen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:08:28 by amuhsen-          #+#    #+#             */
/*   Updated: 2024/12/03 03:38:49 by amuhsen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_arg_content(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '0')
			return (i);
		i++;
	}
	return (0);
}

int	check_args(char **argv)
{
	if (ft_atoi(argv[1]) > PHILO_MAX || ft_atoi(argv[1]) <= 0
		|| check_arg_content(argv[1]) == 1)
		return (write(2, "\033[31mInvalid number of philosophers\n", 37)
			, 1);
	if (ft_atoi(argv[2]) <= 0 || check_arg_content(argv[2]) == 1)
		return (write(2, "\033[31mInvalid time to die\n", 25), 1);
	if (ft_atoi(argv[3]) <= 0 || check_arg_content(argv[3]) == 1)
		return (write(2, "\033[31mInvalid time to eat\n", 25), 1);
	if (ft_atoi(argv[4]) <= 0 || check_arg_content(argv[4]) == 1)
		return (write(2, "\033[31mInvalid time to sleep\n", 27), 1);
	if (argv[5] && (ft_atoi(argv[5]) < 0 || check_arg_content(argv[5]) == 1))
		return (write(2, "\033[31mInvalid N of times each philo must eat\n", 45)
			, 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac != 5 && ac != 6)
		return (write(2, "\033[31mInvalid argument count\n", 29), 1);
	if (check_args(av) == 1)
		return (1);
	load_program(&program, philos);
	load_forks(forks, ft_atoi(av[1]));
	load_philos(philos, &program, forks, av);
	create_threads(&program, forks);
	//	destroy(NULL, &program, forks);
	return (0);
}
