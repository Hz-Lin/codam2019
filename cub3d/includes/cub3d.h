/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 16:00:11 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/27 16:00:11 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdint.h>

# include "cub3d_struct.h"
# include "../gnl/get_next_line.h"
# include "../minilibx/mlx.h"

/*
** cub3d.c
*/
int             arg_check(t_game *game, char int argc, char **argv)；
int             update_game(t_game *game);
void    	    init_mlx(t_game *game);

/*
** utils
*/
int             skip_wp(char *line, int *i);
int 		    ft_isnum(char *line, int i);
intmax_t    	ft_atoi(char *line, int *i);
int 		    find_num(char *line, int *i, char id);
int 			is_texid(char *line, int i);

size_t      	ft_strlen(const char *s);
int             ft_strcmp(const char *s1, const char *s2);
char           *ft_strdup(const char *s1);
void        	pos_setter(t_pos *pos, double x, double y);
void            print_error(t_game *game, char *str);

/*
** init_game
*/
int	    	    init_game(t_game *game, int save);
void         	init_img(t_img *img)；
void            init_keys(t_key *keys)；
void            init_config(t_config *config);
void        	init_map(t_map *map)；
void            init_view(t_view *view);

/*
** key
*/
int		        keyrelease(int keycode, t_game *game);
int		        keypress(int keycode, t_game *game);

/*
** parse_mapfile
*/
int	        	map_validation(t_game *game, char **map, int x, int y);
void        	copy_map(t_game *game, char **map);
int		        map_validation(t_game *game);
int	        	parse_line(t_game *game, char *line);
int		        parse_mapfile(t_game *game, char *map);

/*
** parse_map_tex
*/
int             check_file_open(char *path);
int             check_img_file(char *path);
void        	get_tex(t_game *game, char *path, t_img *tex);
char	        *parse_path(char *line, int *i, int len);
int	        	parse_tex(t_game *game, t_img *tex, char *line, int *i);

/*
** parse_mapfile_resfc
*/
int	        	parse_color(t_game *game, t_colour *element, char *line, int *i);
int	        	parse_fc(t_game *game, char *line, int *i);
int	        	parse_res(t_game *game, char *line, int *i);
void           config_validation(t_game *game);

/*
** parse_map
*/
void        	set_sprite(t_game *game, t_sprite **list, int x, int y);
void        	set_startpos(t_game *game, char direction, int x, int y);
void        	set_sprit_or_start(t_game *game, char **str, int col, int row);
char        	*input_map(t_game *game, char *line, int *i);
int	        	parse_map(t_game *game, char *line, int *i);

/*
** render_utils
*/
void			shad_distance(t_colour *colour, double dist);
void			draw_pixel(t_game *game, int x, int y, unsigned int colour);
unsigned int	tex_to_pix(t_img *tex, int x, int y);

/*
** render
*/
void	       fc_measurement(t_game *game, t_cfloor *fc, int y, int x);
void	       draw_fc(t_game *game, t_img *tex, int x, int height);
void	       draw_wall(t_game *game, t_line *line, int x, t_img *tex);
int		       render_map(t_game *game);

/*
** raycast
*/
void	        get_view(t_game *game, t_view *view, int x, t_img *tex);
void        	cal_distance(t_game *game, t_view *view);
void	       dda_calculator(t_game *game, t_view *view);
void        	tex_measurement(t_game *game, t_view *view, t_img *tex, double perpdist);
void        	get_outline(t_game *game, t_line *line, double perpdist);

/*
** sprite
*/
void        	draw_sprite_pixel(t_game *game, t_sprite *sprite, t_render *sp, t_img *tex);
void        	sprite_measurement(t_game *game, t_render *sp);
void        	transform_sprite(t_game *game, t_sprite *sprite, t_render *sp);
void            draw_sprite(t_game *game);

/*
** sprite_sort
*/
t_sprite    	*merge_list(t_sprite *sprites_a, t_sprite *sprites_b);
void	    	split_sprite(t_sprite *sprites_a, t_sprite **sprites_b);
t_sprite    	*sort_sprite(t_sprite *sprites);
t_sprite    	*get_sprite(t_game *game, t_sprite *sprites);

/*
** savescreen
*/
void	        write_data(t_game *game);
void        	shift_n(unsigned char *str, int n);
void	        write_header(t_game *game);
void        	savescreen(t_game *game);

/*
** move
*/
void    	scale_sprite(t_sprite **list, t_pos pos);
void    	move_lr(t_game *game, t_player *player, t_view *view, int dir);
void    	move_ud(t_game *game, t_player *player, t_view *view, int dir);
void    	move_rot(t_view *view, int d);

/*
** exit
*/
void	    clean_sprite(t_sprite **list);
void	    clean_tex(t_game *game, t_img *tex);
void	    clean_map(char **map);
int		    exit_game(t_game *game, int c);

/*
** ui
*/
void    	make_numstr(char *str, int n, int *start);
void    	print_string(char *str, char *src, int *start);
void    	star_quest(t_game *game, t_pos *start);
void    	draw_line(t_game *game, t_pos *start, t_pos *end);
void    	draw_minimap(t_game *game, t_pos *start, t_pos *end);
void    	draw_ui(t_game *game);

#endif
