/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_mapfile.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 18:06:31 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/03 13:38:25 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		fill_data(t_game *game, char *line)
{
	int	i;

	i = 0;
	skip_wp(line, &i);
	if (line[i] == 'R')
		return (parse_res(game, line, &i));
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (parse_tex(game, &game->config.tex[N], line, &i));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (parse_tex(game, &game->config.tex[S], line, &i));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (parse_tex(game, &game->config.tex[W], line, &i));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (parse_tex(game, &game->config.tex[E], line, &i));
	else if (line[i] == 'S' && line[i + 1] != 'O')
		return (parse_tex(game, &game->config.sprite, line, &i));
	else if (line[i] == 'F' || line[i] == 'C')
		return (parse_fc(game, line, &i));
	else if (line[i] == '0' || line[i] == '1' || line[i] == '2')
		return (parse_map(game, line, &i));
	else if (line[i] == '\0' && game->config.map_found)
		return (parse_map(game, line, &i));
	return (!line[i] ? 0 : -1);
}

int		parse_file(t_game *game, char *map)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		put_error(game, "failed to open map file\n");
	while (ret)
	{
		ret = get_next_line(fd, &line);
		if (ret < 0)
			put_error(game, "failed to read from map file\n");
		if (fill_data(game, line) < 0)
			put_error(game, "invalid line in map file\n");
		free(line);
	}
	close(fd);
	if (map_validation(game) < 0)
		return (-1);
	return (0);
}
