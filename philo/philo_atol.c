/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_atol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:53:50 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 10:55:04 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_overflow(char c, long n)
{
	if (((n > LONG_MAX / 10 && c)
		 || (n == LONG_MAX / 10 && c - '0' > LONG_MAX % 10)))
		return (1);
	return (0);
}

long	philo_atol(const char *nptr)
{
	char	*str;
	int		i;
	long	num;

	i = 0;
	str = (char *)nptr;
	while (str[i])
	{
		if (str[i] < '0' || '9' < str[i])
			return (-1);
		i++;
	}
	num = 0;
	i = 0;
	while (str[i])
	{
		num = (num * 10 + (str[i++] - '0'));
		if (check_overflow(str[i], num))
			return (LONG_MAX);
	}
	return (num);
}
