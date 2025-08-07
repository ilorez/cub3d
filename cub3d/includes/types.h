/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:13:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/07 17:18:05 by znajdaou         ###   ########.fr       */
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
  int width;
  int hieght;
  int rows;
  int columns;
  int bs;
  int **arr;
} t_map;

//##################################
//# raycasting
//##################################
typedef struct s_ray {
  t_cor hitv; // hit point in the vertical lines
  t_cor hith; // hit point in the horizontal lines
  int dh; // if the ray facing the down it's 1, if up its -1 
  int dv; // if the ray facing the right it's 1, if up its -1
  double distv;
  double disth;
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


// player
typedef struct s_player {
  int size;
  int dx,dy;
  double angle; // dx => direction in x axis 
  double speed;
  double sp_inc;
  double sp_max;
  double sp_min;
  double rs;// rotation speed
  t_cor pos;
} t_player;


typedef struct s_data
{
	void		*mlx;
	void		*win;
  int frame_count;
  time_t lastf; // last frame
  time_t last_fps_time;
  double delta_time;
  t_player p;
  t_map *map;
}				t_data;

#endif
