/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:31:42 by malasaha          #+#    #+#             */
/*   Updated: 2022/07/29 13:22:34 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

typedef struct s_philo
{
	pthread_t		thread;
	pthread_mutex_t	*lock;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	*l_mutex;
	pthread_mutex_t	*r_mutex;
	int				philo_id;
	int				philo_count;
	long			t_eat;
	long			t_die;
	long			t_sleep;
	long			start_time;
	long			last_meal;
	long			death;
	int				hm_eat;
	int				*ph_dead;
	int				*is_full;
	int				max_eat_count;
	struct timeval	tv;
	long			ms;
	long			start;
}	t_philo;

int				ft_atoi(char *s);
int				check_arg(int ac, char **av);
int				is_digit(char *arr);
void			set_basic(t_philo *philo, char **av);
void			init_philo(t_philo *philo, char **av, int size);
void			set_mutex(t_philo *philo, int size);
void			create_thread(t_philo *philo, int philo_count);
void			dead_check(t_philo *philo);
void			gettime(t_philo *philo);
void			go_kill(t_philo *philo);
int				ft_usleep(t_philo *philo, long ms);
void			take_fork(t_philo *philo);
void			ft_think(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			eat(t_philo *philo);

#endif