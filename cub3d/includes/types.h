/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   types.h                                            :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:37:01 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/18 10:40:05 by znajdaou         ###   ########.fr       */
/*                                                                            */ /* ************************************************************************** */ #ifndef TYPES_H
# define TYPES_H

# include <sys/time.h>
// structs
typedef struct s_cor
{
	double			x;
	double			y;
}					t_cor;

typedef struct s_intcor
{
	int			x;
	int			y;
}					t_intcor;

typedef struct s_img_data
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
  int				endian;
  int w;
  int h;
}					t_img_data;

// texture slot
typedef struct s_tex { t_img_data img; char *path; int loaded; } t_tex;

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
  int side;
}					t_ray;

//##################################
//# Obejcts
//##################################
// rectongle
typedef struct s_rect
{
	t_intcor			pos;
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


typedef struct s_jump
{
    double offset;    // current height of the jump
    double velocity;  // upward speed while jumping
    int is;        // is jumping 
} t_jump;
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
  t_jump jump;
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
typedef struct s_cub_data
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
  char *door_path;
  char *player_path;
	t_color			floor_color;
	t_color			ceiling_color;
	double			angle; // angle as before
  t_intcor pos;
	t_map			map;
	t_player		player;
	int				map_found;
}					t_cub_data;

enum s_texslot 
{ TEX_NO = 0,
  TEX_SO,
  TEX_WE,
  TEX_EA,
  TEX_DOOR,
  TEX_PLAYER,
  TEX_COUNT
};
// time_t lastf; // last frame
typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img_data		img;
	int				frame_count;
	time_t			lastf;
	time_t			last_fps_time;
	double			delta_time;
	t_player		p;
	t_map			*map;
	t_mouse			mouse;
  t_cub_data *map_info;
	int				is_running;
  t_tex tex[TEX_COUNT];
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
