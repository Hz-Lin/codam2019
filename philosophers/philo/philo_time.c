/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_time.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/09 14:29:30 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/22 21:50:22 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_msg(t_philo *philo, char *action, useconds_t time)
{
	if (philo->data->repeat_count != -2 && action[10] == 'e')
	{
		printf("[\033[1;39m%06u]  \033[1;37mPhilo:%03d  %s (%ld/%ld)\n", \
			time, philo->id, action, \
			philo->eat_count + 1, philo->data->repeat_count);
	}
	else
	{
		printf("[\033[1;39m%06u]  \033[1;37mPhilo:%03d  %s\n", \
			time, philo->id, action);
	}
}

useconds_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

int	ft_usleep(useconds_t usec)
{
	useconds_t	before;
	useconds_t	after;

	before = get_time();
	after = before;
	while (after - before < usec)
	{
		if (usleep(usec) == -1)
			return (-1);
		after = get_time();
	}
	return (0);
}

void	print_timestamp(t_list *philos, char *action, useconds_t t)
{
	useconds_t	time;
	t_philo		*philo;
	int			died;
	int			eat_count;

	philo = philos->content;
	pthread_mutex_lock(&philo->data->died_lock);
	died = philo->data->died;
	pthread_mutex_lock(&philo->data->eat_count_lock);
	eat_count = philo->data->eat_count;
	time = get_time() - philo->data->init_time;
	if (philo->data->repeat_count * philo->data->philo_count != \
			eat_count && (!died || action[7] == 'd'))
		print_msg(philo, action, time);
	if (action[10] == 'e')
	{
		philo->data->eat_count++;
		philo->eat_count++;
	}
	pthread_mutex_unlock(&philo->data->eat_count_lock);
	pthread_mutex_unlock(&philo->data->died_lock);
	if (philo->data->repeat_count * philo->data->philo_count != \
			eat_count && (!died || action[7] == 'd'))
		ft_usleep(t);
}
