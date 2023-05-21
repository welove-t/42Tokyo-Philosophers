/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:20 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 11:43:51 by terabu           ###   ########.fr       */
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

static int set_args(int argc, char *argv[], t_args *args)
{
	args->num_philo = philo_atol(argv[1]);
	args->t_die = philo_atol(argv[2]);
	args->t_eat = philo_atol(argv[3]);
	args->t_sleep = philo_atol(argv[4]);
	if (args->num_philo == -1 || args->t_die == -1 ||
		args->t_eat == -1 || args->t_sleep == -1)
	{
		printf("bad argument\n");
		return(1);
	}
	if (argc == 6)
	{
		args->num_must_eat = philo_atol(argv[5]);
		if (args->num_must_eat == -1)
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
	if (set_args(argc, argv, env->args))
		return (1);
	return (0);
}
