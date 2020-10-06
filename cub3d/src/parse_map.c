/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 22:42:35 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 13:21:43 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		check_config(t_game *game)
{
	if (!game->config.screenheight || !game->config.screenwidth)
		put_error(game, "resolution has to be specified before map\n");
	else if (!game->config.tex[N].ptr)
		put_error(game, "north wall texture has to be specified before map\n");
	else if (!game->config.tex[S].ptr)
		put_error(game, "south wall texture has to be specified before map\n");
	else if (!game->config.tex[E].ptr)
		put_error(game, "east wall texture has to be specified before map\n");
	else if (!game->config.tex[W].ptr)
		put_error(game, "west wall texture has to be specified before map\n");
	else if (!game->config.sprite.ptr)
		put_error(game, "sprite texture has to be specified before map\n");
	else if (game->config.floor.colour == 2147483648)
		put_error(game, "floor colour has to be specified before map\n");
	else if (game->config.ceiling.colour == 2147483648)
		put_error(game, "ceiling colour has to be specified before map\n");
}

static void		parse_startpos(t_game *game, char direction, int x, int y)
{
	set_pos(&game->player.pos, x + 0.5, y + 0.5);
	if (direction == 'N')
	{
		game->player.startdir = N;
		set_pos(&game->view.dir, 0, -1);
		set_pos(&game->view.plane, 0.66, 0);
	}
	else if (direction == 'S')
	{
		game->player.startdir = S;
		set_pos(&game->view.dir, 0, 1);
		set_pos(&game->view.plane, -0.66, 0);
	}
	else if (direction == 'E')
	{
		game->player.startdir = E;
		set_pos(&game->view.dir, 1, 0);
		set_pos(&game->view.plane, 0, 0.66);
	}
	else
	{
		game->player.startdir = W;
		set_pos(&game->view.dir, -1, 0);
		set_pos(&game->view.plane, 0, -0.66);
	}
}

static void		read_map(t_game *game, char **str, int col, int row)
{
	if ((*str)[col] == 'N' || (*str)[col] == 'S' ||
		(*str)[col] == 'E' || (*str)[col] == 'W')
	{
		if (game->player.startdir != NONE)
			put_error(game, "multiple player starting positions\n");
		parse_startpos(game, (*str)[col], col, row);
		(*str)[col] = '0';
	}
	else if ((*str)[col] == '2')
	{
		game->map.spritenum++;
		parse_sprite_list(game, &game->map.sprites, col, row);
	}
	else
	{
		free(*str);
		put_error(game, "invalid character in map\n");
	}
}

static char		*write_map(t_game *game, char *line, int *i)
{
	char	*str;
	int		j;
	int		end;

	j = *i;
	while (line[j])
		j++;
	end = j;
	game->map.cols = j > game->map.cols ? j : game->map.cols;
	str = malloc(sizeof(char) * (game->map.cols + 1));
	if (!str)
		put_error(game, "fail to malloc for map rows\n");
	j = 0;
	while (j < game->map.cols)
	{
		str[j] = (j < end) ? line[j] : ' ';
		if (j < end && line[j] && line[j] != '0' &&
				line[j] != '1' && line[j] != ' ')
			read_map(game, &str, j, game->map.rows);
		j++;
	}
	str[j] = '\0';
	return (str);
}

int				parse_map(t_game *game, char *line, int *i)
{
	char	**tmp;
	int		r;

	if (game->config.i < 8)
		check_config(game);
	game->config.map_found = 1;
	r = 0;
	tmp = malloc(sizeof(char *) * (game->map.rows + 2));
	if (!tmp)
		put_error(game, "fail to malloc for map\n");
	while (r < game->map.rows)
	{
		tmp[r] = ft_strdup(game->map.data[r]);
		if (!tmp[r])
			put_error(game, "fail to malloc for map data\n");
		free(game->map.data[r]);
		r++;
	}
	tmp[r] = write_map(game, line, i);
	tmp[r + 1] = NULL;
	if (game->map.rows > 0)
		free(game->map.data);
	game->map.data = tmp;
	game->map.rows++;
	return (0);
}
