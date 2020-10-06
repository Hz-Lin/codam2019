/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_sprites.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 16:34:06 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 22:22:24 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		measure_sprite_line(t_game *game, t_render *sp)
{
	sp->dim.y = abs((int)(game->config.screenheight / sp->transform.y));
	sp->dim.x = abs((int)(game->config.screenheight / sp->transform.y));
	sp->start.y = (int)(-sp->dim.y / 2 + game->config.screenheight / 2);
	sp->start.x = (int)(-sp->dim.x / 2 + sp->screenx);
	if (sp->start.y < 0)
		sp->start.y = 0;
	if (sp->start.x < 0)
		sp->start.x = 0;
	sp->end.y = (int)(sp->dim.y / 2 + game->config.screenheight / 2);
	sp->end.x = (int)(sp->dim.x / 2 + sp->screenx);
	if (sp->end.y >= game->config.screenheight)
		sp->end.y = game->config.screenheight - 1.;
	if (sp->end.x >= game->config.screenwidth)
		sp->end.x = game->config.screenwidth - 1.;
}

static void		inverse_cam(t_game *game, t_sprite *sprite, t_render *sp)
{
	t_pos	relpos;
	double	inv_cam;

	inv_cam = 1. / (game->view.plane.x * game->view.dir.y -
				game->view.dir.x * game->view.plane.y);
	relpos.x = sprite->pos.x - game->player.pos.x;
	relpos.y = sprite->pos.y - game->player.pos.y;
	sp->transform.x = inv_cam * (game->view.dir.y * relpos.x -
								game->view.dir.x * relpos.y);
	sp->transform.y = inv_cam * (-game->view.plane.y * relpos.x +
								game->view.plane.x * relpos.y);
}

void			get_sprites(t_game *game)
{
	t_render	sp;
	t_sprite	*sprite;

	game->map.sprites = sort_sprite(game, game->map.sprites);
	sprite = game->map.sprites;
	while (sprite)
	{
		inverse_cam(game, sprite, &sp);
		sp.screenx = (int)((game->config.screenwidth / 2) *
						(1. + sp.transform.x / sp.transform.y));
		measure_sprite_line(game, &sp);
		drawer_sprite(game, &sp, &game->config.sprite);
		sprite = sprite->next;
	}
}
