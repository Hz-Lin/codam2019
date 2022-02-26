/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_exit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:55:18 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/22 17:53:09 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(t_error error_code)
{
	ft_putstr_fd("philo: ", 2);
	if (error_code == MALLOC_FAILED)
		ft_putstr_fd("failed to malloc\n", 2);
	else if (error_code == THREAD_FAILED)
		ft_putstr_fd("failed to create a thread\n", 2);
	else if (error_code == MUTEX_FAILED)
		ft_putstr_fd("failed to create a mutex\n", 2);
	else if (error_code == PLIST_FAILED)
		ft_putstr_fd("failed to create the philos list\n", 2);
	return (1);
}

static void	philo_clean(t_list *lst)
{
	t_list	*temp;
	t_philo	*p_temp;

	if (!lst)
		return ;
	while (lst)
	{
		temp = lst;
		p_temp = temp->content;
		lst = lst->next;
		pthread_mutex_destroy(&p_temp->fork_lock);
		pthread_mutex_destroy(&p_temp->last_meal_lock);
		pthread_mutex_destroy(&p_temp->data->eat_count_lock);
		pthread_mutex_destroy(&p_temp->data->died_lock);
		free(temp->content);
		free(temp);
	}
}

void	philo_exit(t_list *philos)
{
	t_philo	*p;
	t_list	*temp;

	if (!philos)
		return ;
	temp = philos;
	while (philos)
	{
		p = philos->content;
		if (p->id == p->data->philo_count)
			philos->next = NULL;
		philos = philos->next;
	}
	philo_clean(temp);
}

void	terminate_thread(int philo_count, t_list *philos)
{
	int		i;
	t_list	*start;
	t_philo	*philo;

	i = 0;
	start = philos;
	while (i < philo_count)
	{
		philo = start->content;
		pthread_join(philo->thread_id, NULL);
		start = start->next;
		i++;
	}
}
