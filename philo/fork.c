/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:22:31 by terabu            #+#    #+#             */
/*   Updated: 2023/05/17 10:46:53 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int get_forks(t_philo *philo)
{

	pthread_mutex_lock(philo->mtx_right_fork);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->mtx_left_fork);
	print_msg(philo, "has taken a fork");
	return (0);
}

int put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->mtx_right_fork);
	pthread_mutex_unlock(philo->mtx_left_fork);
	return (0);
}
