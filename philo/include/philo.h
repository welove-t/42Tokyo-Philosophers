/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 10:14:21 by terabu            #+#    #+#             */
/*   Updated: 2023/05/18 15:26:04 by terabu           ###   ########.fr       */
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
	int				id;
	t_env			*env;
	t_args			*args;
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
	pthread_t		master_thread;
	bool			is_end_game;
	pthread_mutex_t	mtx_end_game;
};
struct s_args
{
	int		num_philo;
	time_t	t_die;
	time_t	t_eat;
	time_t	t_sleep;
	long	num_must_eat;
};


int			print_msg(t_philo *philo, char *msg);
void 		put_philo();
long long	get_time();
int			set_args(int argc, char *argv[], t_env *env);
int			init_philo(t_env *env);
int			create_thread(t_env *env);

int			do_eat(t_philo *philo);
int			do_sleep(t_philo *philo);
int			do_think(t_philo *philo);
void		do_wait(time_t wait_time);


// fork
void	pass_right_fork(t_env *env, int i);
void	pass_left_fork(t_env *env, int i);
int 	get_forks(t_philo *philo);
int 	put_forks(t_philo *philo);

// thread
void	*master_func(void *arg);

#endif
