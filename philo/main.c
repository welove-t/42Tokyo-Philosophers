/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:58:52 by terabu            #+#    #+#             */
/*   Updated: 2023/05/15 17:17:39 by terabu           ###   ########.fr       */
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
	// printf("env-philo-1:%d\n",env.philo[0].id);


	// s = get_time();
	// while (true)
	// {
	// 	printf("time:%lld\n", i);
	// 	usleep(10000);
	// 	i = get_time();
	// 	i = i - s;
	// 	if (atoi(argv[2]) < i)
	// 	{
	// 		printf("die\n");
	// 		break ;
	// 	}
	// }
	return (0);
}
