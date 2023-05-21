/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:15:50 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 13:49:32 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_end_game(t_env *env)
{
	pthread_mutex_lock(&env->mtx_end_game);
	if (env->is_end_game)
	{
		pthread_mutex_unlock(&env->mtx_end_game);
		return (1);
	}
	pthread_mutex_unlock(&env->mtx_end_game);
	return (0);
}

int	print_msg(t_philo *philo, char *msg)
{
	if (check_end_game(philo->env))
		return (1);
	pthread_mutex_lock(&philo->env->mtx_print);
	printf("%lld %d %s\n", get_time() - philo->env->t_start, philo->id, msg);
	pthread_mutex_unlock(&philo->env->mtx_print);
	return 0;
}
