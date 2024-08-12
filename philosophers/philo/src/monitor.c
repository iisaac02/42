/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:45:34 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/08/05 11:53:54 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_current_time() - philo->last_meal >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_if_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo[0].num_of_philos)
	{
		if (philo_dead(&philo[i], philo[i].time_to_die))
		{
			print_message(RED "died 💀\n" RC, &philo[i], philo[i].id);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			if (philo->time_to_die)
				printf(YLW "A philosopher has died, WTF are you doing?\n\n" RC);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_if_all_ate2(t_philo *philo)
{
	if (philo->num_times_to_eat > 1)
		printf(YLW "\n%d philosophers have eaten %d times\n\n" RC,
			philo->num_of_philos, philo->num_times_to_eat);
	else if (philo->num_times_to_eat == 1)
		printf(YLW "\n%d philosophers have eaten 1 time\n\n" RC,
			philo->num_of_philos);
}

int	check_if_all_ate(t_philo *philo)
{
	int	i;
	int	finished_eating;

	i = -1;
	finished_eating = 0;
	if (philo[0].num_times_to_eat == -1)
		return (0);
	while (++i < philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philo[i].meal_lock);
	}
	if (finished_eating == philo[0].num_of_philos)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		check_if_all_ate2(philo);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_philo		*philo;

	philo = (t_philo *)pointer;
	while (1)
		if (check_if_dead(philo) == 1 || check_if_all_ate(philo) == 1)
			break ;
	return (pointer);
}
