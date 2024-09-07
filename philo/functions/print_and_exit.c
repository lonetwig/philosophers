/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:02:07 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/21 11:36:46 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	print_and_exit(char *msg)
{
	while (*msg)
	{
		write(2, msg, 1);
		msg++;
	}
	ft_malloc(0, 1);
	return (0);
}
