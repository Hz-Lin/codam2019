/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_two.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 16:49:11 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/08 16:49:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		init_game(t_game *game, int save)
{
	game->mlx_win = NULL;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (-1);
	if (save)
		game->save = open("screenshot.bmp",
						O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else
		game->save = 0;
	if (game->save < 0)
		print_error(game, "Failed to open screenshot file\n");
	game->frame = 1;
	game->player.startdir = NONE;
	game->player.quest = 0;
	pos_setter(&game->player.pos, 0, 0);
	init_img(&game->img);
	init_img(&game->fr1);
	init_img(&game->fr2);
	init_keys(&game->keys);
	init_config(&game->config);
	init_map(&game->map);
	init_view(&game->view);
	return (0);
}
