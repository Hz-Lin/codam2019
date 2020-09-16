/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_mapfile_resfc.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 00:05:37 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 00:05:37 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		parse_color(t_game *game, t_colour *element, char *line, int *i)
{
	int rgb[3];
	int	c;

	c = 0;
	if (element->colour != 2147483648)
		print_error(game, "duplicate floor/celling info\n");
	if (find_num(line, i, line[*i]) < 0)
		return (-1);
	while (line[*i] && c < 3)
	{
		rgb[c] = ft_atoi(line, i);
		if (rgb[c] < 0 || rgb[c] > 255)
			print_error(game, "invalid floor/ceiling values\n");
		if (find_num(line, i, ',') < 0)
			return (-1);
		c++;
	}
	if (c < 3)
		print_error(game, "missing floor/ceiling value\n");
	element->colour = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	game->config.i++;
	return (0);
}

int		parse_fc(t_game *game, char *line, int *i)
{
	if (line[*i + 1] == '-')
		print_error(game, "invalid floor/ceiling values\n");
	if (line[*i] == 'F' && (line[*i + 1] == ' ' ||ft_isnum(line, *i + 1)))
	{
		(*i)++;
		skip_wp(line, i);
		if (ft_isnum(line, *i) || line[*i] == '-')
			return (parse_color(game, &game->config.floor, line, i));
		return (parse_tex(game, &game->config.tex[F], line, i));
	}
	else if (line[*i] == 'C' && (line[*i + 1] == ' ' || ft_isnum(line, *i + 1)))
	{
		(*i)++;
		skip_wp(line, i);
		if (ft_isnum(line, *i) || line[*i] == '-')
			return (parse_color(game, &game->config.ceiling, line, i));
		return (parse_tex(game, &game->config.tex[C], line, i));
	}
	return (-1);
}

int		parse_res(t_game *game, char *line, int *i)
{
	int maxwidth;
	int maxheight;

	if (game->config.screenwidth != 0 || game->config.screenheight != 0)
		print_error(game, "duplicate resolution info\n");
	mlx_get_screen_size(game->mlx, &maxwidth, &maxheight);
	maxwidth = (maxwidth <= 0) ? 2560 : maxwidth;
	maxheight = (maxheight <= 0) ? 1400 : maxheight;
	if (find_num(line, i, line[*i]) < 0)
		return (-1);
	game->config.screenwidth = ft_atoi(line, i);
	if (game->config.screenwidth > maxwidth && !game->save)
		game->config.screenwidth = maxwidth;
	game->config.screenheight = ft_atoi(line, i);
	if (game->config.screenheight > maxheight && !game->save)
		game->config.screenheight = maxheight;
	if (game->config.screenwidth <= 0 || game->config.screenheight <= 0)
		print_error(game, "invalid resolution\n");
	if (game->config.screenwidth > 16384 || game->config.screenheight > 16384)
		print_error(game, "resolution exceeds maximum\n");
	game->config.i++;
	return (0);
}

void	 config_validation(t_game *game)
{
	if (!game->config.screenheight || !game->config.screenwidth)
		print_error(game, "missing resolution info\n");
	else if (!game->config.tex[N].ptr || !game->config.tex[S].ptr ||
			!game->config.tex[E].ptr || !game->config.tex[W].ptr)
		print_error(game, "missing wall texture info\n");
	else if (!game->config.sprite.ptr)
		print_error(game, "missing sprite texture info\n");
	else if ((game-config.tex[F].ptr) || (game->config.ceiling.colour ==
			2147483648 && !game->config.tex[C].ptr))
		print_error>config.floor.colour == 2147483648 &&
			!game->(game, "missing floor/ceiling colour value\n");
}
