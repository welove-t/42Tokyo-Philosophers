/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:58:52 by terabu            #+#    #+#             */
/*   Updated: 2023/05/21 11:35:33 by terabu           ###   ########.fr       */
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
	create_thread(&env);
	return (0);
}
