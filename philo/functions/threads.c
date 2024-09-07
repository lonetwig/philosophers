/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:34:48 by ealislam          #+#    #+#             */
/*   Updated: 2024/09/05 07:57:23 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	get_philo_info(t_philo *philo, t_all *all, int i)
{
	philo->num = i;
	philo->meals_left = all->info.num_of_meals;
	philo->t_last_meal = get_time(all);
	philo->all = all;
	philo->state = i % 2;
	assign_forks(all, philo, i);
	philo->thread = ft_malloc(sizeof(pthread_t), 0);
	if (!philo->thread)
		return (0);
	if (pthread_create(philo->thread, NULL, routine, philo))
		return (print_and_exit("pthread create failed.\n"));
	return (1);
}

int	create_philosophers(t_all *all)
{
	int		i;
	int		num_of_philo;
	t_philo	**philos;

	i = 0;
	num_of_philo = all->info.num_of_philo;
	all->philos = ft_malloc(num_of_philo * (sizeof(t_philo *) + 1), 0);
	if (!all->philos)
		return (0);
	philos = all->philos;
	while (i < num_of_philo)
	{
		philos[i] = ft_malloc(sizeof(t_philo), 0);
		if (!philos[i])
			return (0);
		if (!get_philo_info(philos[i], all, i))
			return (0);
		i++;
	}
	philos[i] = NULL;
	return (1);
}

int	create_checker(t_all *all)
{
	if (pthread_create(&all->checker, NULL, checker_of_death, all))
		return (print_and_exit("pthread create failed.\n"));
	return (1);
}

int	join_threads(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->info.num_of_philo)
	{
		if (pthread_join(*all->philos[i]->thread, NULL))
			return (print_and_exit("pthread join failed.\n"));
		i++;
	}
	if (pthread_join(all->checker, NULL))
		return (print_and_exit("pthread join failed.\n"));
	return (1);
}
