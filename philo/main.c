/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:58:52 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 15:07:50 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	release(t_env *env)
{
	int	num_philo;
	int	i;

	num_philo = env->args->num_philo;
	i = 0;
	free(env->args);
	free(env->mtx_fork);
	free(env->mtx_meal);
	free(env->philo);
	// while (i < num_philo)
	// {
	// 	free()
	// 	i++;
	// }
	return (0);
}

int	main(int argc, char *argv[])
{
	t_env	env;

	if (init_args(argc, argv, &env))
		return (1);
	if (init_philo(&env))
		return (1);
	create_thread(&env);
	release(&env);

	return (0);
}

// __attribute((destructor))
// static void destructor() {
//     system("leaks -q philo");
// }
