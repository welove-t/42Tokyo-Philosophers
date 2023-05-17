/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:17:54 by terabu            #+#    #+#             */
/*   Updated: 2023/05/17 10:51:18 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_wait(t_philo *philo, time_t wait_time)
{
	time_t	t_current;

	t_current = get_time();
	philo->t_last_eat = t_current;
	while (get_time() - t_current < wait_time)
		usleep(100);
	return ;
}


void	eat_counter(t_philo *philo)
{
	philo->cnt_eat++;
}

int	do_eat(t_philo *philo)
{
	if (philo->id == 2)
		usleep(1000);
	if (get_forks(philo))
		return (1);
	print_msg(philo, "is eating");
	do_wait(philo, philo->args->t_eat);
	return (0);
}

int	do_sleep(t_philo *philo)
{
	if (put_forks(philo))
		return (1);
	print_msg(philo, "is sleeping");
	do_wait(philo, philo->args->t_sleep);
	return (0);
}

int do_think(t_philo *philo)
{
	print_msg(philo, "is thinking");
	return (0);
}
