/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 11:41:39 by terabu            #+#    #+#             */
/*   Updated: 2023/05/14 11:56:41 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *philo)
{
	time_t	t_current;

	t_current = get_time();
	philo->t_last_eat = t_current;
	while (get_time() - t_current < philo->args->t_eat)
		usleep(100);
	return (0);
}

int sleeping(t_philo *philo)
{
	time_t	t_current;

	t_current = get_time();
	while (get_time() - t_current < philo->args->t_sleep)
		usleep(100);
	return (0);
}
