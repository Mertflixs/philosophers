/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malasaha <malasaha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:31:09 by malasaha          #+#    #+#             */
/*   Updated: 2022/07/30 12:26:21 by malasaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dead_check(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->lock);
		if (*philo->ph_dead)
			return ;
		pthread_mutex_unlock(philo->lock);
	}
}

void	ft_free(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->philo_count)
		pthread_mutex_destroy(&philo->mutex[i++]);
	pthread_mutex_destroy(philo->lock);
	free(philo->mutex);
	free(philo->lock);
	free(philo->is_full);
	free(philo->ph_dead);
	free(philo);
}

int	is_digit(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] < '0' || arr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		printf("Wrong argument number!\n");
		return (0);
	}
	while (av[i])
	{
		if (is_digit(av[i]) == 0 || ft_atoi(av[i]) <= 0)
		{
			printf("Wrong argument!\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		size;

	if (check_arg(ac, av) == 0 || ac > 6 || ac < 5)
		return (1);
	size = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * size);
	set_mutex(philo, size);
	init_philo(philo, av, size);
	create_thread(philo, size);
	dead_check(philo);
	ft_free(philo);
	return (0);
}
