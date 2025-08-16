/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */ /*   types.h                                            :+:      :+:    :+:   */ /*                                                    +:+ +:+         +:+     */ /*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:13:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/11 14:33:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

#include <sys/time.h>
// structs
typedef struct s_cor
{
	double		x;
	double		y;
}				t_cor;

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
}				t_img_data;

// map
typedef struct s_map{
	t_img_data	data;
  int rows; 
  int columns;
  char **arr;
  int  **grid;
} t_map;


//##################################
//# raycasting
//##################################
//typedef struct s_ray {
//  t_cor hitv; // hit point in the vertical lines
//  t_cor hith; // hit point in the horizontal lines
//  int dh; // if the ray facing the down it's 1, if up its -1 
//  int dv; // if the ray facing the right it's 1, if up its -1
//  double distv;
//  double disth;
//} t_ray;
typedef struct s_ray {
  t_cor hit;
  double dist;
} t_ray;

//##################################
//# Obejcts
//##################################
// rectongle
typedef struct s_rect
{
  t_cor pos;
	int width;
	int height;
	int color;
}	t_rect;

// cercle
typedef struct s_cercl
{
  t_cor center;
	int radius;
	int color;
}	t_cercl;

// line
typedef struct s_line
{
  t_cor s; //start
  t_cor e; // end
	int color;
}	t_line;

typedef struct s_color
{
	unsigned char	r; // 0-255
	unsigned char	g; // 0-255
	unsigned char	b; // 0-255
	unsigned char	a; // 0-255 (0 = transparent, 255 = opaque)
}	t_color;

// player
typedef struct s_player {
  int size;
  int dx,dy; // for rotate player and move front and back
  int dv,dh;  // for move player left right or look up down
  double angle; // dx => direction in x axis 
  double speed;
  double sp_inc;
  double sp_max;
  double sp_min;
  double rs;// rotation speed
  double pitch; // stand for look up or look down
  t_cor pos;
} t_player;

// DATA 
typedef struct s_cub_data
{
    char *no_path;
    char *so_path;
    char *we_path;
    char *ea_path;  
    t_color floor_color;
    t_color ceiling_color;
    t_map map;
    t_player player;
    int map_found; // flag to track if map has been found in file
}               t_cub_data;

typedef struct s_mouse {
  int lock;
  int ignore_next_move; // for ignore programming mouse move for centering
    double dx_accum;     // accumulated horizontal movement
    double dy_accum;     // accumulated vertical movement
} t_mouse;


typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img_data	img;
  int frame_count;
  time_t lastf; // last frame
  time_t last_fps_time;
  double delta_time;
  t_player p;
  t_map *map;
  t_mouse mouse;
  int is_running;
}				t_data;

#endif
