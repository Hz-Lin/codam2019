/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/01 17:28:19 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 16:15:10 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		clean_sprite(t_sprite **list)
{
	t_sprite	*tmp;

	if (!list)
		return ;
	tmp = *list;
	while (tmp)
	{
		if ((*list)->next)
			*list = tmp->next;
		if (*list == tmp)
			*list = NULL;
		if (tmp)
			free(tmp);
		tmp = *list;
	}
	*list = NULL;
}

static void		clean_texture(t_game *game, t_img *tex)
{
	int i;

	i = 0;
	while (tex[i].ptr != NULL && i < 4)
	{
		if (tex[i].ptr)
			mlx_destroy_image(game->mlx, tex[i].ptr);
		i++;
	}
}

static void		clean_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

/*
** exit on 0 when called normally
** exit on 1 if there is an error
*/

int				exit_game(t_game *game, int c)
{
	if (c != 1 && game->map.data)
		clean_map(game->map.data);
	if (game->map.perpdist)
		free(game->map.perpdist);
	if (game->config.tex[0].ptr)
		clean_texture(game, game->config.tex);
	if (game->mlx && game->config.sprite.ptr)
		mlx_destroy_image(game->mlx, game->config.sprite.ptr);
	if (game->mlx && game->map.sprites)
		clean_sprite(&game->map.sprites);
	if (game->mlx && game->mlx_win)
	{
		if (game->fr1.ptr)
			mlx_destroy_image(game->mlx, game->fr1.ptr);
		if (game->fr2.ptr)
			mlx_destroy_image(game->mlx, game->fr2.ptr);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	free(game->mlx);
	exit(c);
}

void			put_error(t_game *game, char *str)
{
	if (write(2, "Error\n", 6) < 0)
		put_error(game, "fail to write Error\n");
	if (str)
	{
		if (write(2, str, ft_strlen(str)) < 0)
			put_error(game, "fail to write error message\n");
	}
	exit_game(game, 1);
}
