/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_res.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/03 21:47:31 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/05 17:38:21 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	parse_screensize(char *line, int *i, t_game *game)
{
	(*i)++;
	skip_wp(line, i);
	if (!is_num(line, *i) && line[*i] != '-')
		return (-1);
	game->config.screenwidth = ft_atoi(line, i);
	if (!is_wp(line, *i))
		return (-1);
	skip_wp(line, i);
	if (!is_num(line, *i) && line[*i] != '-')
		return (-1);
	game->config.screenheight = ft_atoi(line, i);
	skip_wp(line, i);
	if (line[*i] != '\0')
		return (-1);
	return (0);
}

int			parse_res(t_game *game, char *line, int *i)
{
	int		maxwidth;
	int		maxheight;

	if (game->config.screenwidth != 0 || game->config.screenheight != 0)
		put_error(game, "duplicate resolution information\n");
	mlx_get_screen_size(game->mlx, &maxwidth, &maxheight);
	maxwidth = (maxwidth <= 0) ? 2560 : maxwidth;
	maxheight = (maxheight <= 0) ? 1400 : maxheight;
	if (parse_screensize(line, i, game) < 0)
		put_error(game, "invalid resolution line\n");
	if (game->config.screenwidth > maxwidth && !game->save)
		game->config.screenwidth = maxwidth;
	if (game->config.screenheight > maxheight && !game->save)
		game->config.screenheight = maxheight;
	if (game->config.screenwidth <= 0 || game->config.screenheight <= 0)
		put_error(game, "invalid negative resolution\n");
	if (game->config.screenwidth > 16384 || game->config.screenheight > 16384)
		put_error(game,
			"exceed max resolution value (16384) for bitmap rendering\n");
	game->config.i++;
	return (0);
}
