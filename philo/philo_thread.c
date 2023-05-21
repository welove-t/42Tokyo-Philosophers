/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:47:32 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 15:34:29 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_one(t_philo *philo)
{
	print_msg(philo, "has taken a fork");
	do_wait(philo->args->t_die);
	print_msg(philo, "died");
}


void	*philo_func(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->args->num_philo == 1)
	{
		philo_one(philo);
		return (NULL);
	}
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(500);
		if (do_eat(philo))
			break ;
		if (do_sleep(philo))
			break ;
		if (do_think(philo))
			break ;
	}
	return (NULL);
}

int	create_thread(t_env *env)
{
	int		i;

	i = 0;
	env->t_start = get_time();
	if (!env->t_start)
		return (1);
	while (i < env->args->num_philo)
	{
		env->philo[i].t_last_eat = env->t_start;
		pthread_create(&env->philo[i].philo_thread,
			NULL, philo_func, &env->philo[i]);
		i++;
	}
	pthread_create(&env->master_thread, NULL, master_func, env);
	i = 0;
	while (i < env->args->num_philo)
	{
		pthread_join(env->philo[i].philo_thread, NULL);
		i++;
	}
	pthread_join(env->master_thread, NULL);
	return (0);
}
