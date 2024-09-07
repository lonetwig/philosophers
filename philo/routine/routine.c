/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:36:38 by ealislam          #+#    #+#             */
/*   Updated: 2024/09/05 08:02:57 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	routine_sleep_start(t_philo *philo)
{
	while (philo->meals_left && philo->all->all_alive)
	{
		sleep_state(philo);
		think_state(philo);
		take_forks(philo);
		eat_state(philo);
		put_forks(philo);
		if (!philo->meals_left)
			break ;
	}
}

static void	routine_think_start(t_philo *philo)
{
	while (philo->meals_left && philo->all->all_alive)
	{
		think_state(philo);
		take_forks(philo);
		eat_state(philo);
		put_forks(philo);
		if (!philo->meals_left)
			break ;
		sleep_state(philo);
	}
}

static void	routine_eat_start(t_philo *philo)
{
	while (philo->meals_left && philo->all->all_alive)
	{
		take_forks(philo);
		eat_state(philo);
		put_forks(philo);
		if (!philo->meals_left)
			break ;
		sleep_state(philo);
		think_state(philo);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->all->info.num_of_philo == 1)
		think_forever(philo);
	if (philo->state == IS_THINKING)
		routine_think_start(philo);
	else if (philo->state == IS_SLEEPING)
		routine_sleep_start(philo);
	else if (philo->state == IS_EATING)
		routine_eat_start(philo);
	return (NULL);
}
