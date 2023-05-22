/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:27:10 by terabu            #+#    #+#             */
/*   Updated: 2023/05/22 10:01:09 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_fork_meal(t_env *env)
{
	int	i;

	env->mtx_fork = malloc(sizeof(pthread_mutex_t) * env->args->num_philo);
	env->mtx_meal = malloc(sizeof(pthread_mutex_t) * env->args->num_philo);
	if (!env->mtx_fork || !env->mtx_meal)
		return (print_error("malloc failed\n"));
	i = 0;
	while (i < env->args->num_philo)
	{
		if (pthread_mutex_init(&env->mtx_fork[i], NULL))
			return (print_error("pthread_mutex_init failed\n"));
		if (pthread_mutex_init(&env->mtx_meal[i], NULL))
			return (print_error("pthread_mutex_init failed\n"));
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
		return (print_error("malloc failed\n"));
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
	if (pthread_mutex_init(&env->mtx_end_game, NULL))
		return (print_error("pthread_mutex_init failed\n"));
	if (pthread_mutex_init(&env->mtx_print, NULL))
		return (print_error("pthread_mutex_init failed\n"));
	return (0);
}
