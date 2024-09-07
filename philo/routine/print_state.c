/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:51:32 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/17 09:44:33 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	print_time(t_philo *philo)
{
	long long	time_passed;
	char		*time_str;

	time_passed = get_time(philo->all) - philo->all->info.t_start;
	time_str = num_to_str(time_passed);
	while (*time_str)
	{
		write(1, time_str, 1);
		time_str++;
	}
}

static void	print_num(int num)
{
	char	*str;

	num++;
	str = num_to_str(num);
	write(1, " ", 1);
	while (*str)
	{
		write(1, str, 1);
		str ++;
	}
	write(1, " ", 1);
}

static void	print_phrase(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->all->typing_mutex);
	if (philo->all->all_alive)
	{
		print_time(philo);
		print_num(philo->num);
		print_phrase(str);
	}
	pthread_mutex_unlock(&philo->all->typing_mutex);
}
