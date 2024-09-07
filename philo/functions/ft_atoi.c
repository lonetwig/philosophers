/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:32:54 by ealislam          #+#    #+#             */
/*   Updated: 2024/08/17 07:54:35 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static int	is_space(char c)
{
	if (c == '\f' || c == '\n' || c == ' ')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static void	is_oper(const char **str, int *neg)
{
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*neg = (*neg) * -1;
		(*str)++;
	}
}

int	check_overflow(long long n)
{
	int	result;

	result = n * 10;
	if (result / 10 == n)
	{
		return (0);
	}
	return (1);
}

int	check_max(long long n, int neg)
{
	if (n > 2147483647 && neg == 1)
		return (1);
	if (n > 2147483648 && neg == -1)
		return (1);
	return (0);
}

int	ft_atoi(const char *str, long long *n)
{
	int					neg;

	*n = 0;
	neg = 1;
	while (is_space(*str))
		str++;
	is_oper(&str, &neg);
	if (!*str)
		return (1);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		if (check_overflow((*n)))
			return (1);
		*n = (*n) * 10 + (*str) - '0';
		str++;
	}
	if (check_max((*n), neg))
		return (check_max(*n, neg));
	*n = (*n) * neg;
	return (0);
}
