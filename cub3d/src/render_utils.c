/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 21:09:20 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/15 21:09:20 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			shad_distance(t_colour *colour, double dist)
{
	if (dist <= 1.)
		return ;
	colour->colour = ((int)(colour->rgb.r / dist) << 16 |
						(int)(colour->rgb.g / dist) << 8 |
						(int)(colour->rgb.b / dist));
}

void			draw_pixel(t_game *game, int x, int y, unsigned int colour)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.linesize + (x * (game->img.bpp / 8)));
	*(unsigned int *)dst = colour;
}

unsigned int	tex_to_pix(t_img *tex, int x, int y)
{
	unsigned int	colour;
	char			*dst;

	y = y > 0 ? y : 0;
	dst = tex->addr + (y * tex->linesize + (x * (tex->bpp / 8)));
	colour = *(unsigned int *)dst;
	return (colour);
}
