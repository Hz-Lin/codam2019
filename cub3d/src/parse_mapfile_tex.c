/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_map_tex.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 23:11:43 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/14 23:11:43 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     check_file_open(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    close(fd);
    if (fd >= 0)
        return (0)
    return (-1)；
}

int     check_img_file(char *path)
{
    if (!ft_strcmp(&path[len - 4], ".xpm"))
		return (0);
	if (!ft_strcmp(&path[len - 4], ".png"))
		return (1);
    return (-1);
}

void	get_tex(t_game *game, char *path, t_img *tex)
{
	int		format;
	int		len;

	format = -1;
	format = check_img_file(path);
	if (format == -1)
		print_error(game, "invalid texture file\n");
	if (check_file_open(path) < 0)
		print_error(game, "Failed to open texture file\n");
	if (format == xpm)
		tex->ptr = mlx_xpm_file_to_image(game->mlx, path,
					&tex->width, &tex->height);
	else if (format == png)
		tex->ptr = mlx_png_file_to_image(game->mlx, path,
					&tex->width, &tex->height);
	if (tex->ptr == NULL)
		print_error(game, "fail to read image\n");
	len = ft_strlen(path);
	if (!ft_strcmp(&path[len - 12], "sprite_3.xpm") ||
		!ft_strcmp(&path[len - 12], "sprite_3.png"))
		game->map.star = 1;
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp,
					&tex->linesize, &tex->endian);
	if (tex->addr == NULL)
		print_error(game, "fail to retrieve image address\n");
}

char	*parse_path(char *line, int *i, int len)
{
	char	*path;
	int		j;

	j = 0;
	path = malloc(sizeof(char) * (len + 1));
	if (!path)
		return (0);
	while (line[*i] && j < len)
	{
		path[j] = line[*i];
		j++;
		(*i)++;
	}
	path[j] = '\0';
	return (path);
}

int		parse_tex(t_game *game, t_img *tex, char *line, int *i)
{
	char	*path;
	int		len;

	len = 0;
	path = NULL;
	if (tex->ptr)
		print_error(game, "duplicate texture information\n");
	if (is_texid(line, *i))
	{
		while (!skip_wp(line, i))
			(*i)++;
	}
	skip_wp(line, i);
	while (line[*i + len] && line[*i + len] != '\n')
		len++;
	path = parse_path(line, i, len);
	if (!path)
		print_error(game, "malloc texture path fail\n");
	get_tex(game, path, tex);
	free(path);
	game->config.i++;
	return (0);
}
