/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:41:40 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/21 11:03:14 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long long	get_time(t_all *all)
{
	long long	time;

	if (gettimeofday(&all->tv, NULL))
		return (print_and_exit("gettimeofday failed."));
	time = all->tv.tv_sec * 1000LL + all->tv.tv_usec / 1000;
	return (time);
}
