/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 14:18:50 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/05 13:46:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	inti_struct(t_game *game)
{
	game->mlx_win = NULL;
	game->mlx = NULL;
	game->save = -1;
	game->frame = 1;
	game->player.startdir = NONE;
	set_pos(&game->player.pos, 0, 0);
	init_img(&game->img);
	init_img(&game->fr1);
	init_img(&game->fr2);
	init_key(&game->keys);
	init_config(&game->config);
	init_map(&game->map);
	init_view(&game->view);
}

int		init_game(t_game *game, int save)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (-1);
	if (save)
		game->save = open("screenshot.bmp",
						O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else
		game->save = 0;
	if (game->save < 0)
		put_error(game, "failed to create screenshot file\n");
	return (0);
}

void	init_mlx(t_game *game)
{
	if (!game->save)
		game->mlx_win = mlx_new_window(game->mlx, game->config.screenwidth,
						game->config.screenheight, "cub3D");
	game->fr1.ptr = mlx_new_image(game->mlx, game->config.screenwidth,
						game->config.screenheight);
	game->fr2.ptr = mlx_new_image(game->mlx, game->config.screenwidth,
						game->config.screenheight);
	game->fr1.addr = mlx_get_data_addr(game->fr1.ptr, &game->fr1.bpp,
						&game->fr1.linesize, &game->fr1.endian);
	game->fr2.addr = mlx_get_data_addr(game->fr2.ptr, &game->fr2.bpp,
						&game->fr2.linesize, &game->fr2.endian);
	if ((!game->save && !game->mlx_win) || !game->fr1.ptr || !game->fr2.ptr)
		put_error(game, "mlx initialisation failed\n");
}
