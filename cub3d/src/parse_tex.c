/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_tex.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 22:40:31 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 19:27:37 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char		*get_path(char *line, int *i, int len)
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

static int		format_check(char *path)
{
	int len;

	len = ft_strlen(path);
	if (!ft_strcmp(&path[len - 4], ".xpm"))
		return (1);
	if (!ft_strcmp(&path[len - 4], ".png"))
		return (2);
	return (-1);
}

static int		file_open_check(char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	close(fd);
	if (fd >= 0)
		return (0);
	return (-1);
}

static void		get_tex(t_game *game, char *path, t_img *tex)
{
	int		format;

	format = -1;
	format = format_check(path);
	if (format == -1)
		put_error(game, "invalid texture file format\n");
	if (file_open_check(path) < 0)
		put_error(game, "fail to open texture file\n");
	if (format == 1)
		tex->ptr = mlx_xpm_file_to_image(game->mlx, path,
					&tex->width, &tex->height);
	else if (format == 2)
		tex->ptr = mlx_png_file_to_image(game->mlx, path,
					&tex->width, &tex->height);
	if (tex->ptr == NULL)
		put_error(game, "fail to read image\n");
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp,
					&tex->linesize, &tex->endian);
	if (tex->addr == NULL)
		put_error(game, "fail to retrieval image address\n");
}

int				parse_tex(t_game *game, t_img *tex, char *line, int *i)
{
	char	*path;
	int		len;

	len = 0;
	path = NULL;
	if (tex->ptr)
		put_error(game, "duplicate texture info\n");
	if (line[*i] == 'S' && line[*i + 1] != 'O')
		(*i)++;
	else
		(*i) += 2;
	skip_wp(line, i);
	while (line[*i + len] && line[*i + len] != '\n')
		len++;
	path = get_path(line, i, len);
	if (!path)
		put_error(game, "fail to malloc for tex path\n");
	get_tex(game, path, tex);
	free(path);
	game->config.i++;
	return (0);
}
