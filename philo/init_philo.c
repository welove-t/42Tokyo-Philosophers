/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:27:10 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 11:42:15 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork_meal(t_env *env)
{
	int	i;

	env->mtx_fork = malloc(sizeof(pthread_mutex_t) * env->args->num_philo);
	env->mtx_meal = malloc(sizeof(pthread_mutex_t) * env->args->num_philo);
	if (!env->mtx_fork || !env->mtx_meal)
		return (1);
	i = 0;
	while (i < env->args->num_philo)
	{
		if (pthread_mutex_init(&env->mtx_fork[i], NULL))
			return (1);
		if (pthread_mutex_init(&env->mtx_meal[i], NULL))
			return (1);
		i++;
	}
	return (0);
}


int	init_philo(t_env *env)
{
	int	i;

	if (init_fork_meal(env))
		return (1);
	env->philo = malloc(sizeof(t_philo) * env->args->num_philo);
	if (!env->philo)
		return (1);
	i = 0;
	while (i < env->args->num_philo)
	{
		env->philo[i].env = env;
		env->philo[i].args = env->args;
		env->philo[i].id = i + 1;
		env->philo[i].cnt_eat = 0;
		pass_right_fork(env, i);
		pass_left_fork(env, i);
		i++;
	}
	env->is_end_game = false;
	pthread_mutex_init(&env->mtx_end_game, NULL);
	return 0;
}
