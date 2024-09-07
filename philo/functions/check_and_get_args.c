/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_get_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:03:11 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/23 10:04:02 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	append_value(long long *num, t_all *all)
{
	all->info.num_of_philo = num[0];
	all->info.t_to_die = num[1];
	all->info.t_to_eat = num[2];
	all->info.t_to_sleep = num[3];
	all->info.num_of_meals = num[4];
	all->info.t_start = get_time(all);
	all->all_alive = 1;
}

static int	check_length(int length)
{
	if (length > 5)
		return (print_and_exit("too many arguments.\n"));
	if (length < 4)
		return (print_and_exit("too few arguments.\n"));
	return (1);
}

static int	get_value(long long *num, char *arg, int *counter)
{
	char	**str;

	str = ft_split(arg, ' ');
	if (!str)
		return (0);
	while (*str)
	{
		if (ft_atoi(*str, num + (*counter)) || *(num + (*counter)) < 0)
			return (print_and_exit("argument not valid.\n"));
		(*counter)++;
		str++;
	}
	return (1);
}

static int	get_args(int argc, char **argv, t_all *all)
{
	int			i;
	long long	*num;
	char		**str;
	int			counter;

	all->info = (t_info){0};
	num = ft_malloc(sizeof(long long) * 5, 0);
	if (!num)
		return (0);
	num[4] = -1;
	i = 1;
	counter = 0;
	while (i < argc)
	{
		if (!get_value(num, argv[i], &counter))
			return (0);
		if (counter > 5)
			break ;
		i++;
	}
	append_value(num, all);
	return (check_length(counter));
}

int	check_and_get_args(int argc, char **argv, t_all *all)
{
	if (!get_args(argc, argv, all))
		return (0);
	if (all->info.num_of_philo == 0)
		return (print_and_exit("there are no philosophers.\n"));
	return (1);
}
