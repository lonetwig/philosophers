/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_put_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:12:40 by ealislam          #+#    #+#             */
/*   Updated: 2024/09/05 07:55:28 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	if (!philo->all->all_alive)
		return ;
	print_state(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	if (!philo->all->all_alive)
		return ;
	print_state(philo, "has taken a fork");
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
