/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:13:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/03 12:08:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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
  int block_size;
  int **arr;
} t_map;

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
    int r;
    int g;
    int b;
}               t_color;

// player
typedef struct s_player {
  t_cor pos;
  double dx,dy,angle; // dx => direction in x axis 
  char dir; // dir  => direction // 'N', 'S', 'E', 'W'
  int size;
  int speed;
  double rs;// rotation speed
} t_player;


// MAP
// typedef struct s_map
// {
//     char **grid; // 2D array of map data
//     int height;
//     int width;
//     t_player player;
// }               t_map;

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
    int map_found; // flag to track if map has been found in file
}               t_cub_data;


typedef struct s_data
{
	void		*mlx;
	void		*win;
  t_player p;
  t_map *map;
}				t_data;

#endif
