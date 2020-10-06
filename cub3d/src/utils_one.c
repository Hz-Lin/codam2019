/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_one.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 00:14:15 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 14:24:34 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_pos(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

int		skip_wp(char *line, int *i)
{
	if (line[*i] != '\t' && line[*i] != '\n' && line[*i] != '\r'
		&& line[*i] != '\v' && line[*i] != '\f' && line[*i] != ' ')
		return (0);
	while (line[*i] == '\t' || line[*i] == '\n' || line[*i] == '\r'
		|| line[*i] == '\v' || line[*i] == '\f' || line[*i] == ' ')
		(*i)++;
	return (1);
}

int		is_num(char *line, int i)
{
	if (line[i] && line[i] >= '0' && line[i] <= '9')
		return (1);
	return (0);
}

int		is_wp(char *line, int i)
{
	if (line[i] && (line[i] == '\t' || line[i] == '\n' || line[i] == '\r'
		|| line[i] == '\v' || line[i] == '\f' || line[i] == ' '))
		return (1);
	return (0);
}
