/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:58:52 by terabu            #+#    #+#             */
/*   Updated: 2023/05/17 12:51:49 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char *argv[])
{
	t_env	env;

	if (argc < 3)
		return (1);
	set_args(argc, argv, &env);
	if (init_philo(&env))
		return (1);
	create_thread(&env);
	return (0);
}
