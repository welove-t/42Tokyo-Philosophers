/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:53:26 by terabu            #+#    #+#             */
/*   Updated: 2023/05/18 15:30:52 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_kill(t_philo philo)
{
	print_msg(&philo, "died");
}

int	check_eat_time(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->args->num_philo)
	{
		if (get_time() - env->philo[i].t_last_eat > env->args->t_die)
		{
			do_kill(env->philo[i]);
			return (1);
		}
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
		if (env->philo[i].cnt_eat < env->args->num_must_eat)
			return (0);
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
		if (check_eat_time(env))
		{
			pthread_mutex_lock(&env->mtx_end_game);
			env->is_end_game = true;
			pthread_mutex_unlock(&env->mtx_end_game);
			break ;
		}
		if (check_eat_cnt(env))
		{
			pthread_mutex_lock(&env->mtx_end_game);
			env->is_end_game = true;
			pthread_mutex_unlock(&env->mtx_end_game);
			break ;
		}
	}
	return (NULL);
}
