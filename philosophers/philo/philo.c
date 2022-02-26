/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:06:09 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/23 10:28:11 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error_usage(void)
{
	ft_putstr_fd("philo: ", 2);
	ft_putstr_fd("invalid number of arguments\n", 2);
	printf("usage: philo <num_of_philo> <time_to_die> <time_to_eat>");
	printf(" <time_to_sleep> [<num_of_times_each_philo_must_eat>]\n");
	return (1);
}

static int	initial_data_struct(t_data *d)
{
	d->init_time = get_time();
	d->died = 0;
	d->eat_count = 0;
	if (pthread_mutex_init(&d->died_lock, NULL))
	{
		print_error(MUTEX_FAILED);
		return (1);
	}
	if (pthread_mutex_init(&d->eat_count_lock, NULL))
	{
		pthread_mutex_destroy(&d->died_lock);
		print_error(MUTEX_FAILED);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;
	t_list	*philos;

	if (argc != 5 && argc != 6)
		return (print_error_usage());
	d = parse_args(argv);
	if (args_validation(&d) == 1)
		return (1);
	if (initial_data_struct(&d))
		return (1);
	philos = create_philo_list(&d);
	if (!philos)
		return (print_error(PLIST_FAILED));
	ft_lstlast(philos)->next = philos;
	if (philo_start(d.philo_count, philos))
		return (1);
	philo_exit(philos);
	return (0);
}
