/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:17:54 by terabu            #+#    #+#             */
/*   Updated: 2023/05/15 17:13:41 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int get_forks(t_philo *philo)
// {

// }

void	do_wait(t_philo *philo, time_t wait_time)
{
	time_t	t_current;

	t_current = get_time();
	philo->t_last_eat = t_current;
	while (get_time() - t_current < wait_time)
		usleep(100);
	return ;
}


int	do_eat(t_philo *philo)

{
	(void) philo;
	// if (get_forks(philo))
	// 	return (1);
	// if (print_message(philo, MESSAGE_EAT))
	// 	return (unlock_forks(philo, 1));
	// if (eat_timestamp_and_wait(philo))
	// 	return (unlock_forks(philo, 1));
	// if (eat_countnum(philo))
	// 	return (unlock_forks(philo, 1));
	// unlock_forks(philo, RET_SUCCESS);
	return (0);
}
