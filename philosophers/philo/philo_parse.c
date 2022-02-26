/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_parse.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 13:31:57 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/22 11:13:49 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
** only cenvert positive number
** if it is negative or invalid, return -1
*/

static long long	ft_atoi(const char *nptr)
{
	long unsigned	n;

	n = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = 10 * n + (*nptr - '0');
		nptr++;
	}
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr)
		return (-1);
	return (n);
}

static void	print_error_args(char *param, t_error error_code)
{
	ft_putstr_fd("philo: ", 2);
	if (error_code == INV_PHILO_COUNT)
		ft_putstr_fd("invalid number_of_philosopher: ", 2);
	else if (error_code == TOO_MANY_PHILO)
		ft_putstr_fd("to many number_of_philosopher: ", 2);
	else if (error_code == INV_DIE_TIME)
		ft_putstr_fd("invalid time_to_die: ", 2);
	else if (error_code == INV_EAT_TIME)
		ft_putstr_fd("invalid time_to_eat: ", 2);
	else if (error_code == INV_SLEEP_TIME)
		ft_putstr_fd("invalid time_to_sleep: ", 2);
	else if (error_code == INV_REPEAT_COUNT)
		ft_putstr_fd("invalid number_of_times_each_philosopher_must_eat: ", 2);
	if (param)
		ft_putstr_fd(param, 2);
	ft_putstr_fd("\n", 2);
}

t_data	parse_args(char **argv)
{
	t_data	d;

	d.philo_count = ft_atoi(argv[1]);
	if (d.philo_count <= 0)
		print_error_args(argv[1], INV_PHILO_COUNT);
	if (d.philo_count > 200)
		print_error_args(argv[1], TOO_MANY_PHILO);
	d.die_time = ft_atoi(argv[2]);
	if (d.die_time == -1)
		print_error_args(argv[2], INV_DIE_TIME);
	d.eat_time = ft_atoi(argv[3]);
	if (d.eat_time == -1)
		print_error_args(argv[3], INV_EAT_TIME);
	d.sleep_time = ft_atoi(argv[4]);
	if (d.sleep_time == -1)
		print_error_args(argv[4], INV_SLEEP_TIME);
	d.repeat_count = -2;
	if (argv[5])
	{
		d.repeat_count = ft_atoi(argv[5]);
		if (d.repeat_count == -1 || !d.repeat_count)
			print_error_args(argv[5], INV_REPEAT_COUNT);
	}
	return (d);
}

int	args_validation(t_data *d)
{
	if (d->philo_count <= 0 || d->philo_count > 200)
		return (1);
	else if (d->die_time == -1 || d->eat_time == -1 || d->sleep_time == -1)
		return (1);
	else if (d->repeat_count == -1 || !d->repeat_count)
		return (1);
	return (0);
}
