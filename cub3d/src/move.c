/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   move.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 00:20:18 by hlin          #+#    #+#                 */
/*   Updated: 2020/09/16 00:20:18 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	scale_sprite(t_sprite **list, t_pos pos)
{
	t_sprite	*head;

	head = *list;
	while (*list)
	{
		if (pos.x >= (*list)->pos.x - 0.5 && pos.x <= (*list)->pos.x + 0.5 &&
			pos.y >= (*list)->pos.y - 0.5 && pos.y <= (*list)->pos.y + 0.5)
			pos_setter(&(*list)->pos, 0, 0);
		*list = (*list)->next;
	}
	*list = head;
}

void	move_lr(t_game *game, t_player *player, t_view *view, int dir)
{
	t_pos	newpos;

	newpos.x = player->pos.x + (dir * 3.5) * (view->plane.x * MOVE);
	newpos.y = player->pos.y + (dir * 3.5) * (view->plane.y * MOVE);
	if ((int)floor(newpos.x) > 0 && (int)floor(newpos.x) < game->map.cols &&
		game->map.data[(int)player->pos.y][(int)newpos.x] == '0')
		player->pos.x = newpos.x;
	if ((int)floor(newpos.y) > 0 && (int)floor(newpos.y) < game->map.rows &&
		game->map.data[(int)newpos.y][(int)player->pos.x] == '0')
		player->pos.y = newpos.y;
	if (game->map.data[(int)newpos.y][(int)newpos.x] == '2' &&
		game->map.star == 1)
	{
		player->pos.x = newpos.x;
		player->pos.y = newpos.y;
		game->map.data[(int)player->pos.y][(int)player->pos.x] = '0';
		game->map.spritenum--;
		scale_sprite(&game->map.sprites, player->pos);
	}
}

void	move_ud(t_game *game, t_player *player, t_view *view, int dir)
{
	t_pos	newpos;

	newpos.x = player->pos.x + (dir * 3.5) * (view->dir.x * MOVE);
	newpos.y = player->pos.y + (dir * 3.5) * (view->dir.y * MOVE);
	if ((int)floor(newpos.x) > 0 && (int)floor(newpos.x) < game->map.cols &&
		game->map.data[(int)player->pos.y][(int)newpos.x] == '0')
		player->pos.x = newpos.x;
	if ((int)floor(newpos.y) > 0 && (int)floor(newpos.y) < game->map.rows &&
		game->map.data[(int)newpos.y][(int)player->pos.x] == '0')
		player->pos.y = newpos.y;
	if (game->map.data[(int)newpos.y][(int)newpos.x] == '2' &&
		game->map.star == 1)
	{
		player->pos.x = newpos.x;
		player->pos.y = newpos.y;
		game->map.data[(int)player->pos.y][(int)player->pos.x] = '0';
		game->map.spritenum--;
		scale_sprite(&game->map.sprites, player->pos);
	}
}

void	move_rot(t_view *view, int d)
{
	t_pos	plane;
	t_pos	dir;

	plane.x = view->plane.x * cos(d * TURN) + view->plane.y * -sin(d * TURN);
	plane.y = view->plane.x * sin(d * TURN) + view->plane.y * cos(d * TURN);
	dir.x = view->dir.x * cos(d * TURN) + view->dir.y * -sin(d * TURN);
	dir.y = view->dir.x * sin(d * TURN) + view->dir.y * cos(d * TURN);
	view->dir = dir;
	view->plane = plane;
}
