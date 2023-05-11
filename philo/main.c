/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:58:52 by terabu            #+#    #+#             */
/*   Updated: 2023/05/11 15:30:57 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char *argv[])
{
	long long i = 0;
	long long s;

	// put_philo();
	if (argc < 3)
		return (0);
	s = get_time();
	while (true)
	{
		printf("time:%lld\n", i);
		usleep(100000);
		i = get_time();
		i = i - s;
		if (atoi(argv[2]) < i)
		{
			printf("die\n");
			break ;
		}
	}
	return (0);
}
