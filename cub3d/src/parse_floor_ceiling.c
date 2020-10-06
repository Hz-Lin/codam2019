/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_floor_ceiling.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 22:02:35 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/05 17:32:12 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	parse_floor(t_game *game, t_colour *floor, char *line, int *i)
{
	int	rgb[3];
	int c;

	c = 0;
	if (floor->colour != 2147483648)
		put_error(game, "duplicate information of floor\n");
	while (line[*i] && c < 3)
	{
		skip_wp(line, i);
		if (!is_num(line, *i) && line[*i] != '-')
			return (-1);
		rgb[c] = ft_atoi(line, i);
		if (rgb[c] < 0 || rgb[c] > 255)
			put_error(game, "invalid floor values\n");
		skip_wp(line, i);
		if ((c < 2 && line[*i] != ',') || (c == 2 && line[*i] != '\0'))
			return (-1);
		(*i)++;
		c++;
	}
	if (c < 3)
		put_error(game, "invalid number of floor value\n");
	floor->colour = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	game->config.i++;
	return (0);
}

static int	parse_ceiling(t_game *game, t_colour *ceiling, char *line, int *i)
{
	int	rgb[3];
	int c;

	c = 0;
	if (ceiling->colour != 2147483648)
		put_error(game, "duplicate information of ceiling\n");
	while (line[*i] && c < 3)
	{
		skip_wp(line, i);
		if (!is_num(line, *i) && line[*i] != '-')
			return (-1);
		rgb[c] = ft_atoi(line, i);
		if (rgb[c] < 0 || rgb[c] > 255)
			put_error(game, "invalid ceiling values\n");
		skip_wp(line, i);
		if ((c < 2 && line[*i] != ',') || (c == 2 && line[*i] != '\0'))
			return (-1);
		(*i)++;
		c++;
	}
	if (c < 3)
		put_error(game, "invalid number of ceiling value\n");
	ceiling->colour = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	game->config.i++;
	return (0);
}

int			parse_fc(t_game *game, char *line, int *i)
{
	int	res;

	res = 0;
	if (line[*i] == 'F')
	{
		(*i)++;
		skip_wp(line, i);
		res = parse_floor(game, &game->config.floor, line, i);
		if (res < 0)
			put_error(game, "invalid floor line\n");
		return (res);
	}
	else if (line[*i] == 'C')
	{
		(*i)++;
		skip_wp(line, i);
		res = parse_ceiling(game, &game->config.ceiling, line, i);
		if (res < 0)
			put_error(game, "invalid ceiling line\n");
		return (res);
	}
	return (-1);
}
