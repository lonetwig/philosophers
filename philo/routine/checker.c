/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:06:52 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/23 10:29:02 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	everyone_took_their_meals(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->info.num_of_philo)
	{
		if (all->philos[i]->meals_left)
			return (0);
		i++;
	}
	all->all_alive = 0;
	return (1);
}

static int	check_everyone_life(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->info.num_of_philo)
	{
		if (get_time(all) - all->philos[i]->t_last_meal > all->info.t_to_die)
		{
			print_state(all->philos[i], "died");
			all->all_alive = 0;
			return (1);
		}
		i++;
	}
	return (0);
}

void	*checker_of_death(void *arg)
{
	t_all	*all;

	all = (t_all *)arg;
	while (all->all_alive)
	{
		pthread_mutex_lock(&(all->checker_mutex));
		check_everyone_life(all);
		everyone_took_their_meals(all);
		pthread_mutex_unlock(&(all->checker_mutex));
	}
	return (NULL);
}
