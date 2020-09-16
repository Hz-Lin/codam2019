/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_mapfile.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 00:02:02 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 00:02:02 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		map_validation(t_game *game, char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (0);
	if (map[y][x] == ' ' || ((y == 0 || x == 0 || x == game->map.cols - 1
		|| y == game->map.rows - 1) && map[y][x] != 1))
		print_error(game, "invalid map\n");
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

void	copy_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		map[i] = ft_strdup(game->map.data[i]);
		if (!map[i])
			print_error(game, "fail to malloc map\n");
		i++;
	}
	map[i] = NULL;
}

int		map_validation(t_game *game)
{
	double	*tmp;
	char	*map[game->map.rows + 1];
	int		i;

	i = 0;
	if (!game->map.data)
		print_error(game, "missing map\n");
	if (game->player.startdir == NONE)
		parse_line(game, "missing starting position\n");
	copy_map(game, map);
	map_validation(game, map, game->player.pos.x, game->player.pos.y);
	game->player.quest = game->map.spritenum;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	tmp = malloc(sizeof(double) * game->config.screenwidth);
	if (!tmp)
		print_error(game, "malloc screen fail\n");
	game->map.perpdist = tmp;
	return (0);
}

int		parse_line(t_game *game, char *line)
{
	int		i;

	i = 0;
	skip_wp(line, &i);
	if (line[i] == 'R' && (line[i + 1] == ' ' || ft_isnum(line, i + 1) ||
		line[i + 1] == '-'))
		return (parse_res(game, line, &i));
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (parse_tex(game, &game->config.tex[N], line, &i));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (parse_tex(game, &game->config.tex[S], line, &i));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (parse_tex(game, &game->config.tex[W], line, &i));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (parse_tex(game, &game->config.tex[E], line, &i));
	else if (line[i] == 'S' && line[i + 1] != '0')
		return (parse_tex(game, &game->config.sprite, line, &i));
	else if (line[i] == 'F' || line[i] == 'C')
		return (parse_fc(game, line, &i));
	else if (line[i] == '0' || line[i] == '1' || line[i] == '2')
		return (parse_map(game, line, &i));
	else if (line[i] == '\0' && game->config.map_found)
		return (parse_map(game, line, &i));
	return (!line[i] ? 0 : -1);
}

int		parse_mapfile(t_game *game, char *map)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		error_handler(game, "failed to open map file\n");
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (parse_line(game, line) < 0)
			print_error(game, "invalid line in map file\n");
		free(line);
	}
	close(fd);
	if (map_validation(game) < 0)
		return (-1);
	return (0);
}
