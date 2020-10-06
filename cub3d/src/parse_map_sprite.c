/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_sprite.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 23:08:32 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/02 23:10:51 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		parse_sprite_list(t_game *game, t_sprite **list, int x, int y)
{
	t_sprite *new;

	new = (t_sprite *)malloc(sizeof(t_sprite));
	if (!new)
		put_error(game, "fail to malloc sprite list\n");
	set_pos(&new->pos, x + 0.5, y + 0.5);
	new->dist = 0;
	if (!list)
		new->next = NULL;
	else
	{
		new->next = *list;
	}
	*list = new;
}
