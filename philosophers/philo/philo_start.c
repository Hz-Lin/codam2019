/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_start.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/13 13:06:18 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/23 10:38:49 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_actions(t_list *node, t_philo *philo, t_philo *next)
{
	pthread_mutex_lock(&philo->fork_lock);
	print_timestamp(node, MSG_FORK, 0);
	pthread_mutex_lock(&next->fork_lock);
	print_timestamp(node, MSG_FORK, 0);
	pthread_mutex_lock(&philo->last_meal_lock);
	philo->last_meal = get_time() - philo->data->init_time;
	pthread_mutex_unlock(&philo->last_meal_lock);
	print_timestamp(node, MSG_EAT, philo->data->eat_time);
	print_timestamp(node, MSG_SLEEP, 0);
	pthread_mutex_unlock(&next->fork_lock);
	pthread_mutex_unlock(&philo->fork_lock);
	ft_usleep(philo->data->sleep_time);
	print_timestamp(node, MSG_THINK, 0);
}

static void	*start_thread(void *node)
{
	t_philo	*philo;
	t_philo	*next;
	int		i;

	i = 0;
	philo = ((struct s_list *)node)->content;
	next = ((struct s_list *)node)->next->content;
	if (philo->id % 2 == 0)
	{
		print_timestamp((struct s_list *)node, MSG_THINK, \
			philo->data->eat_time / 2);
	}
	pthread_mutex_lock(&philo->data->died_lock);
	while (philo->id != next->id && !philo->data->died && \
		(philo->data->repeat_count == -2 || i < philo->data->repeat_count))
	{
		pthread_mutex_unlock(&philo->data->died_lock);
		philo_actions(node, philo, next);
		pthread_mutex_lock(&philo->data->died_lock);
		i++;
	}
	pthread_mutex_unlock(&philo->data->died_lock);
	return (NULL);
}

static int	is_philo_died(t_philo *philo, long eat_count, long last_meal)
{
	if (get_time() - philo->data->init_time - last_meal >= \
			philo->data->die_time)
		return (1);
	else if (eat_count == philo->data->philo_count * philo->data->repeat_count)
		return (0);
	return (0);
}

static void	philo_monitor(t_list *start, t_philo *philo)
{
	long	eat_count;
	long	last_meal;

	while (1)
	{
		philo = start->content;
		pthread_mutex_lock(&philo->data->eat_count_lock);
		eat_count = philo->data->eat_count;
		pthread_mutex_unlock(&philo->data->eat_count_lock);
		pthread_mutex_lock(&philo->last_meal_lock);
		last_meal = philo->last_meal;
		pthread_mutex_unlock(&philo->last_meal_lock);
		if (is_philo_died(philo, eat_count, last_meal) == 1)
		{
			pthread_mutex_lock(&philo->data->died_lock);
			philo->data->died = 1;
			pthread_mutex_unlock(&philo->data->died_lock);
			if (eat_count != philo->data->philo_count * \
				philo->data->repeat_count)
				print_timestamp(start, MSG_DIE, 0);
			return ;
		}
		start = start->next;
	}
}

int	philo_start(int philo_count, t_list *philos)
{
	int		i;
	t_list	*start;
	t_philo	*philo;

	i = 0;
	start = philos;
	while (i < philo_count)
	{
		philo = start->content;
		if (pthread_create(&philo->thread_id, NULL, start_thread, start))
		{
			print_error(THREAD_FAILED);
			philo_exit(philos);
			return (1);
		}
		start = start->next;
		i++;
	}
	philo_monitor(start, NULL);
	terminate_thread(philo_count, philos);
	return (0);
}
