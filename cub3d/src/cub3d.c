/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 19:17:05 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 23:00:07 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	extention_check(char *file_name, char *extension)
{
	int		len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (-1);
	else
	{
		if (!ft_strcmp(&file_name[len - 4], extension))
			return (0);
	}
	return (-1);
}

int			arg_check(t_game *game, int argc, char **argv)
{
	if (argc < 2 || argc > 3)
		put_error(game, "invalid number of arguments\n");
	else
	{
		if (extention_check(argv[1], ".cub") < 0)
			put_error(game, "invalid map file extension\n");
		if (argc == 3)
		{
			if (!ft_strcmp(argv[2], "--save"))
				return (1);
			put_error(game, "invalid second argument\n");
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int		screenshot;
	t_game	game;

	screenshot = 0;
	inti_struct(&game);
	if (arg_check(&game, argc, argv) > 0)
		screenshot = 1;
	if (init_game(&game, screenshot) < 0)
		put_error(&game, "failed ro initialise the game\n");
	if (parse_file(&game, argv[1]) < 0)
		put_error(&game, "failed to parse the cub file\n");
	init_mlx(&game);
	render_map(&game);
	mlx_hook(game.mlx_win, 17, 1L << 17, exit_game, &game);
	mlx_hook(game.mlx_win, 2, 1L << 0, keypress, &game);
	mlx_hook(game.mlx_win, 3, 1L << 1, keyrelease, &game);
	mlx_loop_hook(game.mlx, &update_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
