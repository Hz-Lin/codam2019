/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_sprites_sort.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/27 16:38:51 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/03 18:16:00 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		split_sp_list(t_sprite *sprites_a, t_sprite **sprites_b)
{
	t_sprite	*fast;
	t_sprite	*slow;

	fast = sprites_a;
	slow = sprites_a;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	*sprites_b = slow->next;
	slow->next = NULL;
}

static t_sprite	*merge_sp_list(t_sprite *sprites_a, t_sprite *sprites_b)
{
	if (!sprites_a)
		return (sprites_b);
	if (!sprites_b)
		return (sprites_a);
	if (sprites_a->dist > sprites_b->dist)
	{
		sprites_a->next = merge_sp_list(sprites_a->next, sprites_b);
		return (sprites_a);
	}
	else
	{
		sprites_b->next = merge_sp_list(sprites_a, sprites_b->next);
		return (sprites_b);
	}
}

static t_sprite	*sort_sp_list(t_sprite *sprites)
{
	t_sprite	*sprites_b;

	if (!sprites || !sprites->next)
		return (sprites);
	split_sp_list(sprites, &sprites_b);
	sprites = sort_sp_list(sprites);
	sprites_b = sort_sp_list(sprites_b);
	return (merge_sp_list(sprites, sprites_b));
}

t_sprite		*sort_sprite(t_game *game, t_sprite *sprites)
{
	t_sprite	*list;
	t_pos		pos;
	t_pos		relpos;

	list = sprites;
	set_pos(&pos, game->player.pos.x, game->player.pos.y);
	while (sprites)
	{
		relpos.x = pos.x - sprites->pos.x;
		relpos.y = pos.y - sprites->pos.y;
		sprites->dist = (relpos.x * relpos.x + relpos.y * relpos.y);
		sprites = sprites->next;
	}
	list = sort_sp_list(list);
	return (list);
}
