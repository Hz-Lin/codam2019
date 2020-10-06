/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/23 19:20:47 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/05 17:56:29 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include "./mlx/mlx.h"
# include "./gnl/get_next_line.h"

# define TURN 0.02
# define MOVE 0.01

# define MV_UP 13
# define MV_DW 1
# define MV_LF 0
# define MV_RT 2
# define LEFT 123
# define RIGHT 124
# define ESC 53

typedef	enum	e_dir
{
	NONE = -1, N, S, E, W
}				t_dir;

typedef struct	s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}				t_rgb;

typedef union	u_colour
{
	unsigned int	colour;
	t_rgb			rgb;
}				t_colour;

typedef struct	s_key
{
	unsigned int	key_up;
	unsigned int	key_down;
	unsigned int	key_left;
	unsigned int	key_right;
	unsigned int	key_rotl;
	unsigned int	key_rotr;
}				t_key;

typedef struct	s_pos
{
	double			x;
	double			y;
}				t_pos;

typedef struct	s_player
{
	t_pos			pos;
	t_dir			startdir;
}				t_player;

typedef struct	s_render
{
	t_pos			transform;
	int				screenx;
	t_pos			start;
	double			start0;
	t_pos			end;
	t_pos			dim;
	t_colour		col;
}				t_render;

typedef struct	s_line
{
	int				height;
	int				start;
	int				end;
}				t_line;

typedef	struct	s_view
{
	int				side;
	double			camera_x;
	double			fsdist;
	double			wallhit;
	t_pos			deltadist;
	t_pos			dir;
	t_pos			plane;
	t_pos			raydir;
	t_pos			raypos;
	t_pos			sidedist;
	t_pos			step;
	t_line			line;
}				t_view;

typedef struct	s_sprite
{
	t_pos			pos;
	double			dist;
	struct s_sprite	*next;
}				t_sprite;

typedef struct	s_map
{
	char			**data;
	int				cols;
	int				rows;
	int				spritenum;
	double			*perpdist;
	t_sprite		*sprites;
}				t_map;

typedef struct	s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				linesize;
	int				endian;
	int				width;
	int				height;
	t_pos			t_step;
	t_pos			pos;
}				t_img;

typedef struct	s_config
{
	int				i;
	int				map_found;
	t_img			tex[4];
	t_img			sprite;
	t_colour		floor;
	t_colour		ceiling;
	intmax_t		screenwidth;
	intmax_t		screenheight;
}				t_config;

typedef struct	s_game
{
	void			*mlx_win;
	void			*mlx;
	int				save;
	unsigned short	frame;
	t_img			img;
	t_img			fr1;
	t_img			fr2;
	t_key			keys;
	t_config		config;
	t_map			map;
	t_view			view;
	t_player		player;
}				t_game;

/*
** utils
*/
void			set_pos(t_pos *pos, double x, double y);
int				skip_wp(char *line, int *i);
int				is_num(char *line, int i);
int				is_wp(char *line, int i);
size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
intmax_t		ft_atoi(char *line, int *i);

/*
** initialisation
*/
void			init_view(t_view *view);
void			init_img(t_img *img);
void			init_config(t_config *config);
void			init_key(t_key *keys);
void			init_map(t_map *map);
void			inti_struct(t_game *game);
int				init_game(t_game *game, int save);
void			init_mlx(t_game *game);

/*
** parsing
*/
int				arg_check(t_game *game, int argc, char **argv);
int				parse_file(t_game *game, char *map);
int				fill_data(t_game *game, char *line);
int				parse_res(t_game *game, char *line, int *i);
int				parse_tex(t_game *game, t_img *tex, char *line, int *i);
int				parse_fc(t_game *game, char *line, int *i);
int				parse_map(t_game *game, char *line, int *i);
void			parse_sprite_list(t_game *game, t_sprite **list, int x, int y);
int				map_validation(t_game *game);

/*
** raycasting
*/
int				render_map(t_game *game);
void			get_view(t_game *game, t_view *view, int x, t_img *tex);
void			measure_wall_line(t_game *game, t_line *line,
				double perpdist);
void			measure_tex(t_game *game, t_view *view, t_img *tex,
				double perpdist);
t_sprite		*sort_sprite(t_game *game, t_sprite *sprites);
void			get_sprites(t_game *game);
unsigned int	texpixel_colour(t_img *tex, int x, int y);
void			drawer(t_game *game, t_line *line, int x, t_img *tex);
void			drawer_sprite(t_game *game, t_render *sp, t_img *tex);
void			save_screen(t_game *game);
int				keypress(int keycode, t_game *game);
int				keyrelease(int keycode, t_game *game);
int				update_game(t_game *game);

/*
** exit game and error management
*/
int				exit_game(t_game *game, int c);
void			put_error(t_game *game, char *str);

#endif
