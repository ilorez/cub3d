/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:13:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 11:28:30 by znajdaou         ###   ########.fr       */
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
  int rows;
  int columns;
  int **arr;
} t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img_data	map;
  t_cor   pos;
  t_map *map_arr;
}				t_data;

// rectongle
typedef struct s_rect
{
  t_cor pos;
	int width;
	int height;
	int color;
}	t_rect;


#endif
