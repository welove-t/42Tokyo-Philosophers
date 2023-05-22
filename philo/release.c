/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 07:08:51 by terabu            #+#    #+#             */
/*   Updated: 2023/05/22 10:03:06 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mtx(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->args->num_philo)
	{
		pthread_mutex_destroy(&env->mtx_fork[i]);
		pthread_mutex_destroy(&env->mtx_meal[i]);
		i++;
	}
	pthread_mutex_destroy(&env->mtx_print);
	pthread_mutex_destroy(&env->mtx_end_game);
}

static void	free_env(t_env *env)
{
	free(env->args);
	free(env->mtx_fork);
	free(env->mtx_meal);
	free(env->philo);
}

int	release(t_env *env)
{
	if (!env)
		return (1);
	destroy_mtx(env);
	free_env(env);
	return (0);
}
