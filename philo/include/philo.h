/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:14:21 by terabu            #+#    #+#             */
/*   Updated: 2023/05/15 13:53:33 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo	t_philo;
typedef struct s_args	t_args;
typedef struct s_env	t_env;
struct s_philo
{
	// struct s_data	*data;
	int				id;
	t_env			*env;
	long			cnt_eat;
	time_t			t_last_eat;
	pthread_t		philo_thread;
	pthread_mutex_t	*mtx_left_fork;
	pthread_mutex_t	*mtx_right_fork;
};

struct s_env
{
	t_args			*args;
	t_philo			*philo;
	time_t			t_start;
	pthread_mutex_t	*mtx_meal;
	pthread_mutex_t	*mtx_fork;
};
struct s_args
{
	int		num_philo;
	time_t	t_die;
	time_t	t_eat;
	time_t	t_sleep;
};



void 		put_philo();
long long	get_time();
int			set_args(int argc, char *argv[], t_env *env);
int			init_philo(t_env *env);

#endif