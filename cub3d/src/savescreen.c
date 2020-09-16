/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   savescreen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 23:45:05 by hlin          #+#    #+#                 */
/*   Updated: 2020/09/15 23:45:05 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	write_data(t_game *game)
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
			colour.colour = tex_to_pix(&game->fr1, x, y);
			if (write(game->save, &colour.colour, 3) < 0)
				print_error(game, "failed to write\n");
			if (write(game->save, "0x00", 1) < 0)
				print_error(game, "failed to write\n");
			x++;
		}
		y--;
	}
}

void	shift_n(unsigned char *str, int n)
{
	str[0] = (unsigned char)(n);
	str[1] = (unsigned char)(n >> 8);
	str[2] = (unsigned char)(n >> 16);
	str[3] = (unsigned char)(n >> 24);
}

void	write_header(t_game *game)
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
	shift_n(buffer + 2, n);
	buffer[10] = (unsigned char)(54);
	buffer[14] = (unsigned char)(40);
	n = game->config.screenwidth;
	shift_n(buffer + 18, n);
	n = game->config.screenheight;
	shift_n(buffer + 22, n);
	buffer[26] = (unsigned char)(1);
	buffer[28] = (unsigned char)(32);
	if (write(game->save, buffer, 54) < 0)
		print_error(game, "failed to write\n");
}

void	savescreen(t_game *game)
{
	write_header(game);
	write_data(game);
	close(game->save);
	exit_game(game, 0);
}
