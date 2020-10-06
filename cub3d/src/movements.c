/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movements.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 18:00:21 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/03 20:48:48 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	mover_lr(t_game *game, t_player *player, t_view *view, int dir)
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
}

static void	mover_ud(t_game *game, t_player *player, t_view *view, int dir)
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
}

static void	move_rot(t_view *view, int d)
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

int			update_game(t_game *game)
{
	if (game->keys.key_up || game->keys.key_down || game->keys.key_left ||
		game->keys.key_right || game->keys.key_rotr || game->keys.key_rotl)
	{
		if (game->keys.key_up)
			mover_ud(game, &game->player, &game->view, 1);
		if (game->keys.key_down)
			mover_ud(game, &game->player, &game->view, -1);
		if (game->keys.key_left)
			mover_lr(game, &game->player, &game->view, -1);
		if (game->keys.key_right)
			mover_lr(game, &game->player, &game->view, 1);
		if (game->keys.key_rotr)
			move_rot(&game->view, 1);
		if (game->keys.key_rotl)
			move_rot(&game->view, -1);
		game->frame = (game->frame < 99) ? game->frame + 1 : 2;
		render_map(game);
	}
	return (0);
}
