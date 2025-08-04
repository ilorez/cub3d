/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:13:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/04 13:02:19 by znajdaou         ###   ########.fr       */
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




// player
typedef struct s_player {
  t_cor pos;
  double dx,dy,angle; // dx => direction in x axis 
  int size;
  double speed;
  double sp_inc;
  double sp_max;
  double sp_min;
  double rs;// rotation speed
} t_player;


typedef struct s_data
{
	void		*mlx;
	void		*win;
  t_player p;
  t_map *map;
}				t_data;

#endif
