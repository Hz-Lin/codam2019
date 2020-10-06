/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_check.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 23:13:55 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/02 23:29:46 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		copy_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		map[i] = ft_strdup(game->map.data[i]);
		if (!map[i])
			put_error(game, "fail to malloc while copying map\n");
		i++;
	}
	map[i] = NULL;
}

static int		check_map(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (0);
	if (map[y][x] == ' ' || ((y == 0 || x == 0 || x == game->map.cols - 1
		|| y == game->map.rows - 1) && map[y][x] != 1))
		put_error(game, "invalid map\n");
	if (map[y][x] == '0' || map[y][x] == '2')
		map[y][x] = 'x';
	if (x < game->map.cols - 1)
		check_map(game, map, x + 1, y);
	if (x > 0)
		check_map(game, map, x - 1, y);
	if (y < game->map.rows - 1)
		check_map(game, map, x, y + 1);
	if (y > 0)
		check_map(game, map, x, y - 1);
	if (x < game->map.cols - 1 && y < game->map.rows - 1)
		check_map(game, map, x + 1, y + 1);
	if (x < game->map.cols - 1 && y > 0)
		check_map(game, map, x + 1, y - 1);
	if (x > 0 && y > 0)
		check_map(game, map, x - 1, y - 1);
	if (x > 0 && y < game->map.rows - 1)
		check_map(game, map, x - 1, y + 1);
	return (0);
}

int				map_validation(t_game *game)
{
	double	*tmp;
	char	*map[game->map.rows + 1];
	int		i;

	i = 0;
	if (!game->map.data)
		put_error(game, "missing map\n");
	if (game->player.startdir == NONE)
		put_error(game, "missing starting position\n");
	copy_map(game, map);
	check_map(game, map, game->player.pos.x, game->player.pos.y);
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	tmp = malloc(sizeof(double) * game->config.screenwidth);
	if (!tmp)
		put_error(game, "fail to malloc for map perpdist\n");
	game->map.perpdist = tmp;
	return (0);
}
