/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:20 by terabu            #+#    #+#             */
/*   Updated: 2023/05/18 15:37:00 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_args(int argc, char *argv[], t_env *env)
{
	(void) argc;
	env->args = malloc(sizeof(t_args) * 1);
	env->args->num_philo = atoi(argv[1]);
	env->args->t_die = atoi(argv[2]);
	env->args->t_eat = atoi(argv[3]);
	env->args->t_sleep = atoi(argv[4]);
	if (argc == 6)
		env->args->num_must_eat = atoi(argv[5]);
	return (0);
}
