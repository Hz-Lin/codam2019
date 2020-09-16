/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 17:26:16 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/14 17:26:16 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_img(t_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->linesize = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	pos_setter(&img->t_step, 0, 0);
	pos_setter(&img->pos, 0, 0);
}

void	init_keys(t_key *keys)
{
	keys->up = 0;
	keys->down = 0;
	keys->left = 0;
	keys->right = 0;
	keys->rotl = 0;
	keys->rotr = 0;
}

void	init_config(t_config *config)
{
	config->i = 0;
	config->map_found = 0;
	init_img(&config->tex[N]);
	init_img(&config->tex[S]);
	init_img(&config->tex[E]);
	init_img(&config->tex[W]);
	init_img(&config->tex[F]);
	init_img(&config->tex[C]);
	init_img(&config->sprite);
	config->floor.colour = 2147483648;
	config->ceiling.colour = 2147483648;
	config->screenwidth = 0;
	config->screenheight = 0;
}

void	init_map(t_map *map)
{
	map->data = NULL;
	map->cols = 0;
	map->rows = 0;
	map->spritenum = 0;
	map->star = 0;
	map->sprites = NULL;
	map->perpdist = NULL;
}

void	init_view(t_view *view)
{
    view->side = 0;
	view->camera_x = 0;
	view->fsdist = 0;
	view->wallhit = 0;
	view->line.height = 0;
	view->line.start = 0;
	view->line.end = 0;
	pos_setter(&view->deltadist, 0, 0);
	pos_setter(&view->dir, 0, 0);
	pos_setter(&view->plane, 0, 0);
	pos_setter(&view->raydir, 0, 0);
	pos_setter(&view->raypos, 0, 0);
	pos_setter(&view->sidedist, 0, 0);
	pos_setter(&view->step, 0, 0);
}
