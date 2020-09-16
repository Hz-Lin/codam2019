/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ui.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 00:00:41 by hlin          #+#    #+#                 */
/*   Updated: 2020/09/16 00:00:41 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	make_numstr(char *str, int n, int *start)
{
	int		tmp;
	int		nc;

	tmp = n;
	nc = (n == 0) ? 1 : 0;
	if (n == 0)
		str[*start] = n + '0';
	else
	{
		while (tmp)
		{
			tmp /= 10;
			nc++;
		}
		tmp = nc > 0 ? nc - 1 : 0;
		while (n > 0)
		{
			str[*start + tmp] = (n % 10) + '0';
			n /= 10;
			tmp--;
		}
	}
	*start += nc;
}

void	print_string(char *str, char *src, int *start)
{
	int i;

	i = 0;
	while (src[i])
	{
		str[*start + i] = src[i];
		i++;
	}
	*start += i;
}

void	star_quest(t_game *game, t_pos *start)
{
	char	str[50];
	int		i;

	i = 0;
	while (i < 50)
	{
		str[i] = 0;
		i++;
	}
	i = 0;
	print_string(str, "Stars found: ", &i);
	make_numstr(str, game->player.quest - game->map.spritenum, &i);
	print_string(str, " / ", &i);
	make_numstr(str, game->player.quest, &i);
	mlx_string_put(game->mlx, game->mlx_win, start->x,
					start->y, 0xFFDA0B, str);
}

void	draw_line(t_game *game, t_pos *start, t_pos *end,
							unsigned int colour)
{
	t_pos	save;

	save = *start;
	while (start->x < end->x)
	{
		start->y = save.y;
		while (start->y < end->y)
		{
			draw_pixel(game, start->x, start->y, colour);
			start->y++;
		}
		start->x++;
	}
}

void	draw_minimap(t_game *game, t_pos *start, t_pos *end)
{
	int				x;
	int				y;
	unsigned int	colour;

	x = 0;
	while (x < game->map.cols)
	{
		y = 0;
		while (y < game->map.rows)
		{
			start->x = (int)(end->x - (game->map.cols * 5) + (x * 5));
			start->y = (int)(end->y - (game->map.rows * 5) + (y * 5));
			if (game->map.data[y][x] == '1')
				colour = 0x2E4D62;
			else if (y == (int)game->player.pos.y &&
						x == (int)game->player.pos.x)
				colour = 0xFFDA0B;
			else
				colour = 0x8DA8AF;
			draw_line(game, start, end, colour);
			y++;
		}
		x++;
	}
}

void	draw_ui(t_game *game)
{
	t_pos	mapstart;
	t_pos	mapend;
	t_pos	qtstart;

	if (game->config.screenwidth < 250 || game->config.screenheight < 250)
		return ;
	mapend.x = (int)(game->config.screenwidth * 0.9);
	mapend.y = (int)(game->config.screenheight * 0.9);
	qtstart.x = (int)(game->config.screenwidth * 0.05);
	qtstart.y = (int)(game->config.screenheight * 0.05);
	draw_minimap(game, &mapstart, &mapend);
	if (game->map.star)
		star_quest(game, &qtstart);
}
