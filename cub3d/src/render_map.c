/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 15:46:29 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 13:59:48 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			render_map(t_game *game)
{
	int			x;
	t_img		tex;

	x = 0;
	game->img = (game->frame % 2) ? game->fr1 : game->fr2;
	while (x < game->config.screenwidth)
	{
		set_pos(&game->view.raypos, (int)game->player.pos.x,
					(int)game->player.pos.y);
		get_view(game, &game->view, x, &tex);
		measure_wall_line(game, &game->view.line, game->map.perpdist[x]);
		measure_tex(game, &game->view, &tex, game->map.perpdist[x]);
		drawer(game, &game->view.line, x, &tex);
		x++;
	}
	get_sprites(game);
	if (game->save)
		save_screen(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ptr, 0, 0);
	return (0);
}
