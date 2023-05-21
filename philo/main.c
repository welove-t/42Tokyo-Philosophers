/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:58:52 by terabu            #+#    #+#             */
/*   Updated: 2023/05/22 07:58:20 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"


int	main(int argc, char *argv[])
{
	t_env	env;

	if (init_args(argc, argv, &env))
		return (1);
	if (init_philo(&env))
		return (1);
	if (create_thread(&env))
		return (1);
	if (release(&env))
		return (1);
	return (0);
}

// __attribute((destructor))
// static void destructor() {
//     system("leaks -q philo");
// }
