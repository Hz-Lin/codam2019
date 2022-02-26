/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 11:37:13 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/22 17:00:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	set_node_default(t_data *d, t_philo *node)
{
	node->eat_count = 0;
	node->data = d;
	node->last_meal = 0;
}

static t_philo	*get_node_data(t_data *d, int i)
{
	t_philo	*node;

	node = malloc(sizeof(struct s_philo));
	if (!node)
	{
		print_error(MALLOC_FAILED);
		return (NULL);
	}
	node->id = i + 1;
	node->thread_id = 0;
	if (pthread_mutex_init(&node->fork_lock, NULL))
	{
		pthread_mutex_destroy(&node->fork_lock);
		print_error(MUTEX_FAILED);
		return (NULL);
	}
	if (pthread_mutex_init(&node->last_meal_lock, NULL))
	{
		pthread_mutex_destroy(&node->fork_lock);
		pthread_mutex_destroy(&node->last_meal_lock);
		print_error(MUTEX_FAILED);
		return (NULL);
	}
	set_node_default(d, node);
	return (node);
}

static void	clean_philos(t_list *philos)
{
	t_list	*temp;
	t_philo	*p_temp;

	if (!philos)
		return ;
	while (philos)
	{
		temp = philos;
		p_temp = temp->content;
		philos = philos->next;
		pthread_mutex_destroy(&p_temp->fork_lock);
		pthread_mutex_destroy(&p_temp->last_meal_lock);
		free(temp->content);
		free(temp);
	}
}

t_list	*create_philo_list(t_data *d)
{
	int		i;
	t_list	*philos;
	t_philo	*node;

	i = 0;
	philos = NULL;
	while (i < d->philo_count)
	{
		node = get_node_data(d, i);
		if (node == NULL)
		{
			clean_philos(philos);
			return (NULL);
		}
		ft_lstadd_back(&philos, ft_lstnew(node));
		i++;
	}
	return (philos);
}
