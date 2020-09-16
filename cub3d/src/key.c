/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 00:16:19 by hlin          #+#    #+#                 */
/*   Updated: 2020/09/16 00:16:19 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		keyrelease(int keycode, t_game *game)
{
	if (keycode == MV_UP)
		game->keys.up = 0;
	if (keycode == MV_DW)
		game->keys.down = 0;
	if (keycode == MV_LF)
		game->keys.left = 0;
	if (keycode == MV_RT)
		game->keys.right = 0;
	if (keycode == LEFT)
		game->keys.rotl = 0;
	if (keycode == RIGHT)
		game->keys.rotr = 0;
	return (0);
}

int		keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		exiter(game, 0);
	if (keycode == MV_UP)
		game->keys.up = 1;
	if (keycode == MV_DW)
		game->keys.down = 1;
	if (keycode == MV_LF)
		game->keys.left = 1;
	if (keycode == MV_RT)
		game->keys.right = 1;
	if (keycode == LEFT)
		game->keys.rotl = 1;
	if (keycode == RIGHT)
		game->keys.rotr = 1;
	return (0);
}
