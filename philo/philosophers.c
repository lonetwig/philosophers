/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:16:41 by ealislam          #+#    #+#             */
/*   Updated: 2024/09/01 09:19:24 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_all	all;

	if (!check_and_get_args(argc, argv, &all))
		return (1);
	if (pthread_mutex_init(&all.typing_mutex, NULL) || \
	pthread_mutex_init(&all.checker_mutex, NULL))
		return (1);
	if (!create_forks(&all) || !create_philosophers(&all) || \
	!create_checker(&all))
		return (1);
	if (!join_threads(&all))
		return (1);
	if (!destroy_mutex(&all))
		return (1);
	ft_malloc(0, 1);
}
