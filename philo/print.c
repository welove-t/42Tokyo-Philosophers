/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 12:15:50 by terabu            #+#    #+#             */
/*   Updated: 2023/05/15 13:45:49 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_msg(t_philo *philo, char *msg)
{
	printf("%lld %d %s\n", get_time() - philo->env->t_start, philo->id, msg);
	return 0;
}
