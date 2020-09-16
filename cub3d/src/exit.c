/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 00:22:35 by hlin          #+#    #+#                 */
/*   Updated: 2020/09/16 00:22:35 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_sprite(t_sprite **list)
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

void	clean_tex(t_game *game, t_img *tex)
{
	int i;

	i = 0;
	while (tex[i].ptr != NULL && i < 6)
	{
		if (tex[i].ptr)
			mlx_destroy_image(game->mlx, tex[i].ptr);
		i++;
	}
}

void	clean_map(char **map)
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
** exits on 0 if called normally, -1 if called in error processing
*/

int		exit_game(t_game *game, int c)
{
	if (c != -1 && game->map.data)
		clean_map(game->map.data);
	if (game->map.perpdist)
		free(game->map.perpdist);
	if (game->config.tex[0].ptr)
		clean_tex(game, game->config.tex);
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
