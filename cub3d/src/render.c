/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 17:35:13 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 17:35:13 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fc_measurement(t_game *game, t_cfloor *fc, int y, int x)
{
	double	weight;
	t_view	*view;

	view = &game->view;
	if (!view->side && view->raydir.x > 0 && y == view->line.end)
		pos_setter(&fc->fstart, view->raypos.x,
					view->raypos.y + view->wallhit);
	else if (!view->side && view->raydir.x < 0 && y == view->line.end)
		pos_setter(&fc->fstart, view->raypos.x + 1.,
					view->raypos.y + view->wallhit);
	else if (view->side && view->raydir.y > 0 && y == view->line.end)
		pos_setter(&fc->fstart, view->raypos.x + view->wallhit,
					view->raypos.y);
	else if (view->side && view->raydir.y < 0 && y == view->line.end)
		pos_setter(&fc->fstart, view->raypos.x + view->wallhit,
					view->raypos.y + 1.);
	view->fsdist = game->config.screenheight /
					(2. * y - game->config.screenheight);
	weight = view->fsdist / game->map.perpdist[x];
	fc->pos.x = weight * fc->fstart.x + (1. - weight) * game->player.pos.x;
	fc->pos.y = weight * fc->fstart.y + (1. - weight) * game->player.pos.y;
}

void	draw_fc(t_game *game, t_img *tex, int x, int height)
{
	int			y;
	t_cfloor	fc;
	t_colour	colour;

	y = game->view.line.end;
	while (y < game->config.screenheight)
	{
		fc_measurement(game, &fc, y, x);
		tex->pos.x = (int)(fc.pos.x * tex->width) % tex->width;
		tex->pos.y = (int)(fc.pos.y * tex->height) % tex->height;
		colour.colour = tex_to_pix(tex, tex->pos.x, tex->pos.y);
		shad_distance(&colour, (game->view.fsdist / 2.5));
		if (height != 0)
			draw_pixel(game, x, height - y, colour.colour);
		else
			draw_pixel(game, x, y, colour.colour);
		y++;
	}
}

void	draw_wall(t_game *game, t_line *line, int x, t_img *tex)
{
	int			i;
	int			end;
	t_colour	colour;

	i = !game->config.tex[C].ptr ? 0 : line->start;
	end = !game->config.tex[F].ptr ? game->config.screenheight : line->end;
	colour.colour = 0;
	while (i < end)
	{
		if (i < line->start)
			draw_pixel(game, x, i, game->config.ceiling.colour);
		else if (i >= line->end)
			draw_pixel(game, x, i, game->config.floor.colour);
		else
		{
			colour.colour = tex_to_pix(tex, tex->pos.x, tex->pos.y);
			shad_distance(&colour, (game->map.perpdist[x] / 2.5));
			draw_pixel(game, x, i, colour.colour);
			tex->pos.y += tex->t_step.y;
		}
		i++;
	}
}

int		render_map(t_game *game)
{
	int			j;
	t_img		tex;

	x = 0;
	game->img = (game->frame % 2) ? game->fr1 : game->fr2;
	while (x < game->config.screenwidth)
	{
		pos_setter(&game->view.raypos, (int)game->player.pos.x,
					(int)game->player.pos.y);
		get_view(game, &game->view, x, &tex);//
		get_outline(game, &game->view.line, game->map.perpdist[x]);//
		tex_measurement(game, &game->view, &tex, game->map.perpdist[x]);
		if (game->config.tex[F].ptr)
			draw_fc(game, &game->config.tex[F], x, 0);
		if (game->config.tex[C].ptr)
			draw_fc(game, &game->config.tex[C], x,
						game->config.screenheight);
		draw_wall(game, &game->view.line, x, &tex);
		j++;
	}
	draw_sprite(game);
	if (game->save)
		savescreen(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.ptr, 0, 0);
	return (0);
}
