/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:01:57 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/17 09:31:19 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	size_of_num(long long num)
{
	int	i;

	i = 0;
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	i++;
	return (i);
}

static void	num_to_str_recursive(long long num, char *str)
{
	char	c;

	c = '0' + (num % 10);
	if (num < 10)
	{
		*str = c;
		return ;
	}
	num_to_str_recursive(num / 10, str - 1);
	*str = c;
}

char	*num_to_str(long long num)
{
	char	*str;
	int		size;

	size = size_of_num(num);
	str = ft_malloc (size + 1, 0);
	if (!str)
		return (NULL);
	str[size] = '\0';
	num_to_str_recursive(num, str + size - 1);
	return (str);
}
