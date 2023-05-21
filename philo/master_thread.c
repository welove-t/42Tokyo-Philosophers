/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:53:26 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 16:02:58 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_kill(t_philo philo)
{
	// print_msg(&philo, "died");
	pthread_mutex_lock(&philo.env->mtx_print);
	printf("%lld %d %s\n", get_time() - philo.env->t_start, philo.id, "died");
	pthread_mutex_lock(&philo.env->mtx_end_game);
	philo.env->is_end_game = true;
	pthread_mutex_unlock(&philo.env->mtx_end_game);
	pthread_mutex_unlock(&philo.env->mtx_print);
}

int	check_eat_time(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->args->num_philo)
	{
		pthread_mutex_lock(&env->mtx_meal[i]);
		if (get_time() - env->philo[i].t_last_eat > env->args->t_die)
		{
			pthread_mutex_unlock(&env->mtx_meal[i]);
			do_kill(env->philo[i]);
			return (1);
		}
		pthread_mutex_unlock(&env->mtx_meal[i]);
		i++;
	}
	return (0);
}

int	check_eat_cnt(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->args->num_philo)
	{
		pthread_mutex_lock(&env->mtx_meal[i]);
		if (env->philo[i].cnt_eat < env->args->num_must_eat)
		{
			pthread_mutex_unlock(&env->mtx_meal[i]);
			return (0);
		}
		pthread_mutex_unlock(&env->mtx_meal[i]);
		i++;
	}
	return (1);
}

void	*master_func(void *arg)
{
	t_env	*env;

	env = (t_env *)arg;
	while (1)
	{
		// usleep(1000);
		if (check_eat_time(env))
			break ;
		if (env->is_must_eat && check_eat_cnt(env))
		{
			pthread_mutex_lock(&env->mtx_end_game);
			env->is_end_game = true;
			pthread_mutex_unlock(&env->mtx_end_game);
			break ;
		}
	}
	return (NULL);
}
