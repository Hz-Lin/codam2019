/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawer.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/03 16:54:03 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 22:24:28 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned int		texpixel_colour(t_img *tex, int x, int y)
{
	unsigned int	colour;
	char			*dst;

	y = y > 0 ? y : 0;
	dst = tex->addr + (y * tex->linesize + (x * (tex->bpp / 8)));
	colour = *(unsigned int *)dst;
	return (colour);
}

static void			draw_pixel(t_game *game, int x, int y, unsigned int colour)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.linesize + (x * (game->img.bpp / 8)));
	*(unsigned int *)dst = colour;
}

void				drawer(t_game *game, t_line *line, int x, t_img *tex)
{
	int			i;
	int			end;
	t_colour	colour;

	i = 0;
	end = game->config.screenheight;
	colour.colour = 0;
	while (i < end)
	{
		if (i < line->start)
			draw_pixel(game, x, i, game->config.ceiling.colour);
		else if (i >= line->end)
			draw_pixel(game, x, i, game->config.floor.colour);
		else
		{
			colour.colour = texpixel_colour(tex, tex->pos.x, tex->pos.y);
			draw_pixel(game, x, i, colour.colour);
			tex->pos.y += tex->t_step.y;
		}
		i++;
	}
}

void				drawer_sprite(t_game *game, t_render *sp, t_img *tex)
{
	sp->start0 = sp->start.y;
	while (sp->start.x < sp->end.x)
	{
		tex->pos.x = (int)(256 * (sp->start.x - (-sp->dim.x / 2
						+ sp->screenx)) * tex->width / sp->dim.x) / 256;
		if (sp->transform.y > 0 && sp->transform.y <
			game->map.perpdist[(int)sp->start.x])
		{
			sp->start.y = sp->start0;
			while (sp->start.y < sp->end.y)
			{
				tex->pos.y = (((sp->start.y * 2 - game->config.screenheight +
								sp->dim.y) * tex->height) / sp->dim.y) / 2;
				sp->col.colour = texpixel_colour(tex, tex->pos.x, tex->pos.y);
				if (sp->col.colour && sp->col.rgb.a == 0)
				{
					draw_pixel(game, sp->start.x,
									sp->start.y, sp->col.colour);
				}
				sp->start.y++;
			}
		}
		sp->start.x++;
	}
}
