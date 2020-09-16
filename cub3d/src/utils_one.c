/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_one.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 16:00:45 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/09 16:00:45 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			skip_wp(char *line, int *i)
{
	if (line[*i] != 32 && (line[*i] < 9 || line[*i] > 13))
		return (0);
	while (line[*i] == 32 || (line[*i] >= 9 && line[*i] <= 13))
		(*i)++;
	return (1);
}

int			ft_isnum(char *line, int i)
{
	if (line[i] && line[i] >= '0' && line[i] <= '9')
		return (1);
	return (0);
}

intmax_t	ft_atoi(char *line, int *i)
{
	int			sign;
	intmax_t	n;

	sign = 1;
	n = 0;
	skip_wp(line, i);
	if (line[*i] == '-' || line[*i] == '+')
	{
		if (line[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (ft_isnum(line, *i))
	{
		if (n >= 922337203685477580)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		n = n * 10 + (line[*i] - '0');
		(*i)++;
	}
	return (sign * n);
}

int			find_num(char *line, int *i, char id)
{
	while (line[*i] && !ft_isnum(line, *i) && line[*i] != '-')
	{
		if (line[*i] != exc && line[*i] != 32 &&
			(line[*i] < 9 || line[*i] > 13))
			return (-1);
		(*i)++;
	}
	return (0);
}

int			is_texid(char *line, int i)
{
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
		|| line[i] == 'F' || line[i] == 'C')
		return (1);
	return (0);
}
