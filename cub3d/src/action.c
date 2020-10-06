/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 14:25:42 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/02 23:38:02 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		keypress(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game, 0);
	if (keycode == MV_UP)
		game->keys.key_up = 1;
	if (keycode == MV_DW)
		game->keys.key_down = 1;
	if (keycode == MV_LF)
		game->keys.key_left = 1;
	if (keycode == MV_RT)
		game->keys.key_right = 1;
	if (keycode == LEFT)
		game->keys.key_rotl = 1;
	if (keycode == RIGHT)
		game->keys.key_rotr = 1;
	return (0);
}

int		keyrelease(int keycode, t_game *game)
{
	if (keycode == MV_UP)
		game->keys.key_up = 0;
	if (keycode == MV_DW)
		game->keys.key_down = 0;
	if (keycode == MV_LF)
		game->keys.key_left = 0;
	if (keycode == MV_RT)
		game->keys.key_right = 0;
	if (keycode == LEFT)
		game->keys.key_rotl = 0;
	if (keycode == RIGHT)
		game->keys.key_rotr = 0;
	return (0);
}
