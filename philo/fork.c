/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:22:31 by terabu            #+#    #+#             */
/*   Updated: 2023/05/22 10:00:51 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pass_right_fork(t_env *env, int i)
{
	if (i == env->args->num_philo - 1)
	{
		if (i % 2 == 0)
			env->philo[i].mtx_right_fork = &env->mtx_fork[i];
		else
			env->philo[i].mtx_right_fork = &env->mtx_fork[0];
	}
	else
	{
		if (i % 2 == 0)
			env->philo[i].mtx_right_fork = &env->mtx_fork[i];
		else
			env->philo[i].mtx_right_fork = &env->mtx_fork[i + 1];
	}
}

void	pass_left_fork(t_env *env, int i)
{
	if (i == env->args->num_philo - 1)
	{
		if (i % 2 == 0)
			env->philo[i].mtx_left_fork = &env->mtx_fork[0];
		else
			env->philo[i].mtx_left_fork = &env->mtx_fork[i];
	}
	else
	{
		if (i % 2 == 0)
			env->philo[i].mtx_left_fork = &env->mtx_fork[i + 1];
		else
			env->philo[i].mtx_left_fork = &env->mtx_fork[i];
	}
}

int	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mtx_right_fork);
	if (print_msg(philo, "has taken a fork"))
		return (1);
	pthread_mutex_lock(philo->mtx_left_fork);
	if (print_msg(philo, "has taken a fork"))
		return (1);
	return (0);
}

int	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->mtx_right_fork);
	pthread_mutex_unlock(philo->mtx_left_fork);
	return (0);
}
