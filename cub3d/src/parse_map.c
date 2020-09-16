/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 00:06:45 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 00:06:45 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_sprite(t_game *game, t_sprite **list, int x, int y)
{
	t_sprite *new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	if (!new)
		print_error(game, "fail to malloc sprite\n");
	pos_setter(&new->pos, x + 0.5, y + 0.5);
	new->dist = 0;
	if (!list)
		new->next = NULL;
	else
	{
		new->next = *list;
	}
	*list = new;
}

void	set_startpos(t_game *game, char direction, int x, int y)
{
	pos_setter(&game->player.pos, x + 0.5, y + 0.5);
	if (direction == 'N')
	{
		game->player.startdir = N;
		pos_setter(&game->view.dir, 0, -1);
		pos_setter(&game->view.plane, 0.66, 0);
	}
	else if (direction == 'S')
	{
		game->player.startdir = S;
		pos_setter(&game->view.dir, 0, 1);
		pos_setter(&game->view.plane, -0.66, 0);
	}
	else if (direction == 'E')
	{
		game->player.startdir = E;
		pos_setter(&game->view.dir, 1, 0);
		pos_setter(&game->view.plane, 0, 0.66);
	}
	else
	{
		game->player.startdir = W;
		pos_setter(&game->view.dir, -1, 0);
		pos_setter(&game->view.plane, 0, -0.66);
	}
}

void	set_sprit_or_start(t_game *game, char **str, int col, int row)
{
	if ((*str)[col] == 'N' || (*str)[col] == 'S' ||
		(*str)[col] == 'E' || (*str)[col] == 'W')
	{
		if (game->player.startdir != NONE)
			print_error(game, "multiple starting positions\n");
		set_startpos(game, (*str)[col], col, row);
		(*str)[col] = '0';
	}
	else if ((*str)[col] == '2')
	{
		game->map.spritenum++;
		set_sprite(game, &game->map.sprites, col, row);
	}
	else
	{
		free(*str);
		print_error(game, "invalid character in map\n");
	}
}

char	*input_map(t_game *game, char *line, int *i)
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
		print_error(game, "fail to malloc map.cols\n");
	j = 0;
	while (j < game->map.cols)
	{
		str[j] = (j < end) ? line[j] : ' ';
		if (j < end && line[j] && line[j] != '0' &&
				line[j] != '1' && line[j] != ' ')
			set_sprit_or_start(game, &str, j, game->map.rows);
		j++;
	}
	str[j] = '\0';
	return (str);
}


int		parse_map(t_game *game, char *line, int *i)
{
	char	**tmp;
	int		r;

	if (game->config.i < 8)
		config_validation(game);
	game->config.map_found = 1;
	r = 0;
	tmp = malloc(sizeof(char *) * (game->map.rows + 2));
	if (!tmp)
		print_error(game, "fail to malloc map.rows\n");
	while (r < game->map.rows)
	{
		tmp[r] = ft_strdup(game->map.data[r]);
		if (!tmp[r])
			print_error(game, "fail to malloc map.data\n");
		free(game->map.data[r]);
		r++;
	}
	tmp[r] = input_map(game, line, i);
	tmp[r + 1] = NULL;
	if (game->map.rows > 0)
		free(game->map.data);
	game->map.data = tmp;
	game->map.rows++;
	return (0);
}
