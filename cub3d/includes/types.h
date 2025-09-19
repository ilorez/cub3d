/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:23:48 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/19 10:03:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "settings.h"
# include <sys/time.h>

typedef enum s_block_types
{
	BLK_NONE = 0,
	BLK_WALL = 1,
	BLK_DOOR = 3
}					t_block_types;

// structs
typedef struct s_cor
{
	double			x;
	double			y;
}					t_cor;

typedef struct s_intcor
{
	int				x;
	int				y;
}					t_intcor;

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				endian;
	int				w;
	int				h;
}					t_img_data;

// used in ft put image
// x: dst x
// y: dst y
// w: draw width  (target width)
// h: draw height (target height)
typedef struct s_put_params
{
	int				x;
	int				y;
	int				w;
	int				h;
}					t_put_params;
// texture slot
typedef struct s_tex
{
	t_img_data		img;
	char			*path;
	int				loaded;
}					t_tex;

// map
typedef struct s_map
{
	t_img_data		data;
	int				rows;
	int				columns;
	char			**arr;
	int				**grid;
}					t_map;

//##################################
//# raycasting
//##################################
// typedef struct s_ray {
//  t_cor hitv; // hit point in the vertical lines
//  t_cor hith; // hit point in the horizontal lines
//  int dh; // if the ray facing the down it's 1, if up its -1
//  int dv; // if the ray facing the right it's 1, if up its -1
//  double distv;
//  double disth;
//} t_ray;
typedef struct s_ray
{
	t_cor			hit;
	double			dist;
	int				color;
	int				side;
	t_block_types	type;
	double			ang;
}					t_ray;

//##################################
//# Obejcts
//##################################
// rectongle
typedef struct s_rect
{
	t_intcor		pos;
	int				width;
	int				height;
	int				color;
}					t_rect;

// cercle
typedef struct s_cercl
{
	t_cor			center;
	int				radius;
	int				color;
}					t_cercl;

// line
typedef struct s_line
{
	t_cor			s;
	t_cor			e;
	int				color;
}					t_line;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

// 1:current height of the jump
// 2:upward speed while jumping
// 3:is jumping
typedef struct s_jump
{
	double			offset;
	double			velocity;
	int				is;
}					t_jump;
// player
// int dx, dy;   // for rotate player and move front and back
// int dv, dh;   // for move player left right or look up down
// double angle; // dx => direction in x axis
// double rs;    // rotation speed
// double pitch; // stand for look up or look down
typedef struct s_player
{
	int				size;
	int				dx;
	int				dy;
	int				dv;
	int				dh;
	double			angle;
	double			speed;
	double			sp_inc;
	double			sp_max;
	double			sp_min;
	double			rs;
	double			pitch;
	t_cor			pos;
	t_jump			jump;
}					t_player;

// int ignore_next_move; // for ignore programming mouse move for centering
// double dx_accum;      // accumulated horizontal movement
typedef struct s_mouse
{
	int				lock;
	int				ignore_next_move;
	double			dx_accum;
	double			dy_accum;
}					t_mouse;

// DATA
// int map_found; // flag to track if map has been found in file
// cf: check if color founded
typedef struct s_cub_data
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*door_path;
	t_color			floor_color;
	t_color			ceiling_color;
	double			angle;
	t_intcor		pos;
	t_map			map;
	t_player		player;
	int				map_found;
	int				c_check;
	int				f_check;
}					t_cub_data;

typedef enum s_texslot
{
	TEX_NO = 0,
	TEX_SO,
	TEX_WE,
	TEX_EA,
	TEX_DOOR,
	TEX_COUNT
}					t_texslot;

typedef struct s_pl_animation
{
	t_tex			texs[TEX_PLA_COUNT];
	int				i;
	int				frame_count;
	int				frame_order[12];
	// animation serie order: 0 1 2 3 4 ,  3 2 ,  3 4 ,  3 2 1 0
	time_t			last_frame;
	time_t			duration;
	int				is_animating;
}					t_pl_animation;

typedef struct s_raycl_params
{
	int				vskip;
	int				hskip;
	int				cl;
	double			ang;
	t_ray			rh;
	t_ray			rv;
	int				dh;
	int				dv;
}					t_raycl_args;

// time_t lastf; // last frame
typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img_data		img;
	int				frame_count;
	time_t			lastf;
	double			delta_time;
	t_player		p;
	t_map			*map;
	t_mouse			mouse;
	t_cub_data		*map_info;
	int				is_running;
	t_tex			tex[TEX_COUNT];
	t_pl_animation	pa;
}					t_data;

// int i0, i1; // visible columns [i0..i1]
// int j0, j1; // visible rows    [j0..j1]
// int offx;   // ceil(mstart_x0)
// int offy;   // ceil(mstart_y0)
typedef struct s_minimap_info
{
	int				i0;
	int				i1;
	int				j0;
	int				j1;
	int				offx;
	int				offy;
	t_map			*game;
	double			mstart_x0;
	double			mstart_y0;
}					t_minimap_info;

#endif
