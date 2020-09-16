/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d_struct.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/11 21:34:51 by anonymous     #+#    #+#                 */
/*   Updated: 2020/09/11 21:34:51 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# define MV_UP 13
# define MV_DW 1
# define MV_LF 0
# define MV_RT 2
# define LEFT 123
# define RIGHT 124
# define ESC 53

# define TURN 0.03
# define MOVE 0.025

typedef enum		e_form
{
	nofile = -1, xpm = 0, png = 1
}					t_form;

typedef	enum		e_dir
{
	NONE = -1, N, S, E, W, F, C
}					t_dir;

typedef struct		s_key
{
	unsigned int	up;
	unsigned int	down;
	unsigned int	left;
	unsigned int	right;
	unsigned int	rotl;
	unsigned int	rotr;
}					t_key;

typedef struct		s_rgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_rgb;

typedef union		u_colour
{
	unsigned int	colour;
	t_rgb			rgb;
}					t_colour;

typedef struct		s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct		s_player
{
	t_pos			pos;
	t_dir			startdir;
	int				quest;
}					t_player;

typedef struct		s_render
{
	t_pos			transform;
	int				screenx;
	t_pos			start;
	double			start0;
	t_pos			end;
	t_pos			dim;
	t_colour		col;
}					t_render;

typedef struct		s_cfloor
{
	t_pos			pos;
	t_pos			fstart;
}					t_cfloor;

typedef struct		s_line
{
	int				height;
	int				start;
	int				end;
}					t_line;

typedef	struct		s_view
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
}					t_view;

typedef struct		s_sprite
{
	t_pos			pos;
	double			dist;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_map
{
	char			**data;
	int				cols;
	int				rows;
	int				spritenum;
	int				star;
	double			*perpdist;
	t_sprite		*sprites;
}					t_map;

typedef struct		s_img
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
}					t_img;

typedef struct		s_config
{
	int				i;
	int				map_found;
	t_img			tex[6];
	t_img			sprite;
	t_colour		floor;
	t_colour		ceiling;
	intmax_t		screenwidth;
	intmax_t		screenheight;
}					t_config;

typedef struct		s_game
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
}					t_game;

#endif
