/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:20 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 16:02:12 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_argc(int argc)
{
	if (!(argc == 5 || argc == 6))
	{
		printf("number of bad arguments\n");
		return (1);
	}
	return (0);
}

static int set_args(int argc, char *argv[], t_env *env)
{
	env->args->num_philo = philo_atol(argv[1]);
	env->args->t_die = philo_atol(argv[2]);
	env->args->t_eat = philo_atol(argv[3]);
	env->args->t_sleep = philo_atol(argv[4]);
	if (env->args->num_philo == -1 || env->args->t_die == -1 ||
		env->args->t_eat == -1 || env->args->t_sleep == -1)
	{
		printf("bad argument\n");
		return(1);
	}
	env->is_must_eat = false;
	if (argc == 6)
	{
		env->args->num_must_eat = philo_atol(argv[5]);
		env->is_must_eat = true;
		if (env->args->num_must_eat == -1)
		{
			printf("bad argument\n");
			return (1);
		}
	}
	return (0);
}

int	init_args(int argc, char *argv[], t_env *env)
{
	if (check_argc(argc))
		return (1);
	env->args = malloc(sizeof(t_args) * 1);
	if (!env->args)
	{
		printf("malloc failed\n");
		return (1);
	}
	if (set_args(argc, argv, env))
		return (1);
	return (0);
}
