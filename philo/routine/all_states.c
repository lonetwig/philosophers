/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_states.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:32:23 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/23 10:23:27 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	ft_sleep(long long timelapse, t_philo *philo)
{
	int			to_sleep;
	long long	end_time;

	to_sleep = 300;
	end_time = get_time(philo->all) + timelapse;
	while (get_time(philo->all) < end_time)
	{
		if (!philo->all->all_alive)
			break ;
		usleep(to_sleep);
	}
}

void	think_forever(t_philo *philo)
{
	t_info	*info;

	if (!philo->all->all_alive)
		return ;
	print_state(philo, "is thinking");
	info = &philo->all->info;
	ft_sleep((info->t_to_die + 10), philo);
}

void	sleep_state(t_philo *philo)
{
	t_info	*info;

	if (!philo->all->all_alive)
		return ;
	info = &philo->all->info;
	pthread_mutex_lock(&(philo->all->checker_mutex));
	if (philo->all->all_alive)
		print_state(philo, "is sleeping");
	pthread_mutex_unlock(&(philo->all->checker_mutex));
	ft_sleep(info->t_to_sleep, philo);
}

void	think_state(t_philo *philo)
{
	if (!philo->all->all_alive)
		return ;
	pthread_mutex_lock(&(philo->all->checker_mutex));
	if (philo->all->all_alive)
		print_state(philo, "is thinking");
	pthread_mutex_unlock(&(philo->all->checker_mutex));
}

void	eat_state(t_philo *philo)
{
	t_info	*info;

	if (!philo->all->all_alive)
		return ;
	info = &philo->all->info;
	pthread_mutex_lock(&(philo->all->checker_mutex));
	if (philo->all->all_alive)
		print_state(philo, "is eating");
	philo->t_last_meal = get_time(philo->all);
	pthread_mutex_unlock(&(philo->all->checker_mutex));
	ft_sleep(info->t_to_eat, philo);
	(philo->meals_left)--;
}
