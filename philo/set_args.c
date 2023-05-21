/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:20 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 10:55:53 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_args(int argc, char *argv[], t_env *env)
{
	(void) argc;
	env->args = malloc(sizeof(t_args) * 1);
	env->args->num_philo = philo_atol(argv[1]);
	env->args->t_die = philo_atol(argv[2]);
	env->args->t_eat = philo_atol(argv[3]);
	env->args->t_sleep = philo_atol(argv[4]);
	if (argc == 6)
		env->args->num_must_eat = philo_atol(argv[5]);
	return (0);
}
