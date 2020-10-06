/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/25 15:50:07 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/03 21:59:43 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_view(t_view *view)
{
	view->side = 0;
	view->camera_x = 0;
	view->fsdist = 0;
	view->wallhit = 0;
	view->line.height = 0;
	view->line.start = 0;
	view->line.end = 0;
	set_pos(&view->deltadist, 0, 0);
	set_pos(&view->dir, 0, 0);
	set_pos(&view->plane, 0, 0);
	set_pos(&view->raydir, 0, 0);
	set_pos(&view->raypos, 0, 0);
	set_pos(&view->sidedist, 0, 0);
	set_pos(&view->step, 0, 0);
}

void	init_img(t_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->linesize = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	set_pos(&img->t_step, 0, 0);
	set_pos(&img->pos, 0, 0);
}

void	init_config(t_config *config)
{
	config->i = 0;
	config->map_found = 0;
	init_img(&config->tex[N]);
	init_img(&config->tex[S]);
	init_img(&config->tex[E]);
	init_img(&config->tex[W]);
	init_img(&config->sprite);
	config->floor.colour = 2147483648;
	config->ceiling.colour = 2147483648;
	config->screenwidth = 0;
	config->screenheight = 0;
}

void	init_key(t_key *keys)
{
	keys->key_up = 0;
	keys->key_down = 0;
	keys->key_left = 0;
	keys->key_right = 0;
	keys->key_rotl = 0;
	keys->key_rotr = 0;
}

void	init_map(t_map *map)
{
	map->data = NULL;
	map->cols = 0;
	map->rows = 0;
	map->spritenum = 0;
	map->sprites = NULL;
	map->perpdist = NULL;
}
