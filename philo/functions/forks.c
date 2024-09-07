/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:39:43 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/21 11:15:58 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	assign_forks(t_all *all, t_philo *philo, int i)
{
	int	num_of_philo;

	num_of_philo = all->info.num_of_philo;
	philo->left_fork = all->forks[i];
	if (num_of_philo == 1)
	{
		philo->right_fork = all->forks[0];
		philo->left_fork = NULL;
		return ;
	}
	if (i == num_of_philo - 1)
		philo->right_fork = all->forks[0];
	else
		philo->right_fork = all->forks[i + 1];
}

int	create_forks(t_all *all)
{
	int	i;
	int	num_of_philo;

	i = 0;
	num_of_philo = all->info.num_of_philo;
	all->forks = ft_malloc(num_of_philo * (sizeof(t_mutex *) + 1), 0);
	if (!all->forks)
		return (0);
	while (i < num_of_philo)
	{
		all->forks[i] = ft_malloc(sizeof(t_mutex), 0);
		if (!all->forks[i])
			return (0);
		if (pthread_mutex_init(all->forks[i], NULL))
			return (print_and_exit("pthread mutex init failed.\n"));
		i++;
	}
	return (1);
}

int	destroy_mutex(t_all *all)
{
	int	i;
	int	num_of_philo;

	i = 0;
	num_of_philo = all->info.num_of_philo;
	while (i < num_of_philo)
	{
		if (pthread_mutex_destroy(all->forks[i]) != 0)
			return (print_and_exit("mutex destroy failed.\n"));
		i++;
	}
	if (pthread_mutex_destroy(&(all->typing_mutex)) != 0)
		return (print_and_exit("mutex destroy failed.\n"));
	if (pthread_mutex_destroy(&(all->checker_mutex)) != 0)
		return (print_and_exit("mutex destroy failed.\n"));
	return (1);
}
