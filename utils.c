/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:41:49 by malasaha          #+#    #+#             */
/*   Updated: 2022/07/30 12:20:23 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	gettime(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	gettimeofday(&philo->tv, NULL);
	philo->ms = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	if (philo->start == 0)
		philo->start = philo->ms;
	philo->start_time = (philo->ms) - (philo->start);
	pthread_mutex_unlock(philo->lock);
}

void	go_kill(t_philo *philo)
{
	pthread_mutex_lock(philo->lock);
	if (!*philo->ph_dead)
	{
		printf("%ld %d is died\n", philo->start_time, philo->philo_id);
		*philo->ph_dead = 1;
	}
	pthread_mutex_unlock(philo->lock);
}

int	ft_usleep(t_philo *philo, long ms)
{
	long	time;

	gettime(philo);
	time = philo->start_time;
	while (philo->start_time < (ms + time))
	{
		gettime(philo);
		if (philo->start_time > philo->death)
		{
			go_kill(philo);
			return (0);
		}
		usleep(100);
	}
	return (1);
}
