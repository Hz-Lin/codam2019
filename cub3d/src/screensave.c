/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screensave.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 20:03:52 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/03 21:42:12 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	assign_n(unsigned char *str, int n)
{
	str[0] = (unsigned char)(n);
	str[1] = (unsigned char)(n >> 8);
	str[2] = (unsigned char)(n >> 16);
	str[3] = (unsigned char)(n >> 24);
}

static void	write_header(t_game *game)
{
	int				i;
	int				n;
	unsigned char	buffer[54];

	i = 0;
	n = 0;
	while (i < 54)
	{
		buffer[i] = (unsigned char)(0);
		i++;
	}
	buffer[0] = (unsigned char)('B');
	buffer[1] = (unsigned char)('M');
	n = game->config.screenwidth * game->config.screenheight * 4 + 54;
	assign_n(buffer + 2, n);
	buffer[10] = (unsigned char)(54);
	buffer[14] = (unsigned char)(40);
	n = game->config.screenwidth;
	assign_n(buffer + 18, n);
	n = game->config.screenheight;
	assign_n(buffer + 22, n);
	buffer[26] = (unsigned char)(1);
	buffer[28] = (unsigned char)(32);
	if (write(game->save, buffer, 54) < 0)
		put_error(game, "fail to write header\n");
}

static void	write_data(t_game *game)
{
	int				x;
	int				y;
	t_colour		colour;

	y = game->config.screenheight - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < game->config.screenwidth)
		{
			colour.colour = texpixel_colour(&game->fr1, x, y);
			if (write(game->save, &colour.colour, 3) < 0)
				put_error(game, "fail to write data\n");
			if (write(game->save, "0x00", 1) < 0)
				put_error(game, "fail to write data\n");
			x++;
		}
		y--;
	}
}

void		save_screen(t_game *game)
{
	write_header(game);
	write_data(game);
	close(game->save);
	exit_game(game, 0);
}
