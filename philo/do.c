/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:17:54 by terabu            #+#    #+#             */
/*   Updated: 2023/05/17 13:49:22 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	do_wait(time_t wait_time)
{
	time_t	t_current;

	t_current = get_time();
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
	if (print_msg(philo, "is eating"))
		return (1);
	philo->t_last_eat = get_time();
	do_wait(philo->args->t_eat);
	return (0);
}

int	do_sleep(t_philo *philo)
{
	if (put_forks(philo))
		return (1);
	if (print_msg(philo, "is sleeping"))
		return (1);
	do_wait(philo->args->t_sleep);
	return (0);
}

int do_think(t_philo *philo)
{
	if (print_msg(philo, "is thinking"))
		return (1);
	return (0);
}
