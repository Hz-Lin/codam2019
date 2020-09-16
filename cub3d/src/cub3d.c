/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/07 23:57:29 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/07 23:57:29 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     arg_check(t_game *game, char int argc, char **argv)
{
    int     len;

    len = 0;
    if (argc < 2)
        print_error(game, "no map file\n");
    if (argc >= 2)
    {
        len = ft_strlen(argv[1]);
        if (!ft_strcmp(&((const char *)argv[1])[len - 4], ".cub"))
            print_error(game, "invalid map file\n");
        if (argc == 3)
        {
            if (!ft_strcmp(argv[2], "--save"))
                return (1);
            print_error(game, "invalid second argument\n");
        }
    }
    return (0);
}

int     update_game(t_game *game)
{
    if (game->keys.up || game->keys.down || game->keys.left ||
		game->keys.right || game->keys.rotl || game->keys.rotr)
	{
		if (game->keys.up)
			move_ud(game, &game->player, &game->view, 1);
		if (game->keys.down)
			move_ud(game, &game->player, &game->view, -1);
		if (game->keys.right)
			move_lr(game, &game->player, &game->view, 1);
		if (game->keys.left)
			move_lr(game, &game->player, &game->view, -1);
		if (game->keys.rotr)
			move_rot(&game->view, 1);
		if (game->keys.rotl)
			move_rot(&game->view, -1);
		game->frame = (game->frame < 99) ? game->frame + 1 : 2;
		render_map(game);
		draw_ui(game); 
	}
	return (0);
}

void	init_mlx(t_game *game)
{
	if (!game->save)
		game->mlx_win = mlx_new_window(game->mlx, game->config.screenwidth,
						game->config.screenheight, "cub3D");
	game->fr1.ptr = mlx_new_image(game->mlx, game->config.screenwidth,
						game->config.screenheight);
	game->fr2.ptr = mlx_new_image(game->mlx, game->config.screenwidth,
						game->config.screenheight);
	game->fr1.addr = mlx_get_data_addr(game->fr1.ptr, &game->fr1.bpp,
						&game->fr1.linesize, &game->fr1.endian);
	game->fr2.addr = mlx_get_data_addr(game->fr2.ptr, &game->fr2.bpp,
						&game->fr2.linesize, &game->fr2.endian);
	if ((!game->save && !game->mlx_win) || !game->fr1.ptr || !game->fr2.ptr)
		print_error(game, "mlx initialisation failed\n");
}

int     main(int argc, char **argv)
{
    t_game  game;
    int     save;

    save = 0;
    if (arg_checker(&game, argc, argv) > 0)
        save = 1;
    if (init_game(&game, save) < 0)
        print_error(game, "Initialisation failed\n");
    if (parse_mapfile(&game, argv[1]) < 0)
        print_error(game, "File parsing failed\n");
    init_mlx(&game);
    render_map(&game);
    draw_ui(&game);
    mlx_hook(game.mlx_win, 17, 1L << 17, exit_game, &game);
    mlx_hook(game.mlx_win, 2, 1L << 0, keypress, &game);
    mlx_hook(game.mlx_win, 3, 1L << 1, keyrelease, &game);
    mlx_loop_hook(game.mlx, &update_game, &game);
    mlx_loop(game.mlx);
    return (0);
}
