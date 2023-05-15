/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:32:20 by terabu            #+#    #+#             */
/*   Updated: 2023/05/15 13:53:17 by terabu           ###   ########.fr       */
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
	puts("set_args");
	return (0);
}
