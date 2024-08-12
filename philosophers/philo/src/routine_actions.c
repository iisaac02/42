/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-la-f <ide-la-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 09:53:35 by ide-la-f          #+#    #+#             */
/*   Updated: 2024/08/08 10:26:39 by ide-la-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_message(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

void	ph_think(t_philo *philo)
{
	print_message(GREEN "is thinking 💡" RC, philo, philo->id);
}

void	ph_sleep(t_philo *philo)
{
	print_message(CYAN "is sleeping 💤" RC, philo, philo->id);
	ph_usleep(philo->time_to_sleep);
}

void	ph_eat2(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		ph_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
}

void	ph_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->r_fork);
	else
		pthread_mutex_lock(philo->l_fork);
	print_message(MAGENTA "has taken a fork 🍴" RC, philo, philo->id);
	ph_eat2(philo);
	print_message(MAGENTA "has taken a fork 🍴" RC, philo, philo->id);
	philo->eating = 1;
	print_message(BROWN "is eating 🍝" RC, philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ph_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
