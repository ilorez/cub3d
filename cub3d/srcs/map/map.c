/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:13 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/03 11:05:43 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	render_checked_map_rect_int(t_img_data img, int color, int ix, int iy)
{
	int (x0), (x1), (y0), (y1);
	int (x), (y);
	x0 = ix;
	if (ix < 0)
		x0 = 0;
	x1 = ix + BLOCK_SIZE;
	if (x1 > MAP_SIZE)
		x1 = MAP_SIZE;
	y0 = iy;
	if (iy < 0)
		y0 = 0;
	y1 = iy + BLOCK_SIZE;
	if (y1 > MAP_SIZE)
		y1 = MAP_SIZE;
	x = x0 - 1;
	while (++x < x1)
	{
		y = y0 - 1;
		while (++y < y1)
			ft_put_pixel(img, (t_cor){(double)x, (double)y}, color);
	}
	return (0);
}

// mstart: start point on rendering the min map
// i0/j0 : first block shown in the mini map
// offx: integer offsets to avoid floor in loops: floor(n - x) == n - ceil(x)
static inline void	minimap_prepare(t_minimap_info *c, t_data *data)
{
	c->game = data->map;
	c->mstart_x0 = data->p.pos.x - MAP_SIZE / 2.0;
	c->mstart_y0 = data->p.pos.y - MAP_SIZE / 2.0;
	c->offx = (int)ceil(c->mstart_x0);
	c->offy = (int)ceil(c->mstart_y0);
	c->i0 = (int)floor(c->mstart_x0 / (double)BLOCK_SIZE);
	c->i1 = (int)floor((c->mstart_x0 + (double)MAP_SIZE - 1.0)
			/ (double)BLOCK_SIZE);
	c->j0 = (int)floor(c->mstart_y0 / (double)BLOCK_SIZE);
	c->j1 = (int)floor((c->mstart_y0 + (double)MAP_SIZE - 1.0)
			/ (double)BLOCK_SIZE);
	if (c->i0 < 0)
		c->i0 = 0;
	if (c->j0 < 0)
		c->j0 = 0;
	if (c->i1 >= c->game->columns)
		c->i1 = c->game->columns - 1;
	if (c->j1 >= c->game->rows)
		c->j1 = c->game->rows - 1;
	ft_bzero(c->game->data.addr, MAP_SIZE * MAP_SIZE * (c->game->data.bpp / 8));
}

// img_x position of this cell column in the minimap image
static inline void	minimap_render_column(const t_minimap_info *c, int bi)
{
	int	img_x;
	int	bj;
	int	img_y;

	img_x = bi * (int)BLOCK_SIZE - c->offx;
	bj = c->j0;
	while (bj <= c->j1)
	{
		img_y = bj * (int)BLOCK_SIZE - c->offy;
		if (c->game->grid[bj][bi] == 1)
			render_checked_map_rect_int(c->game->data, COLOR_WHITE, img_x,
				img_y);
		else if (c->game->grid[bj][bi] == 3)
			render_checked_map_rect_int(c->game->data, COLOR_PURPLE, img_x,
				img_y);
		else if (c->game->grid[bj][bi] == -3)
			render_checked_map_rect_int(c->game->data, COLOR_MAGENTA, img_x,
				img_y);
		++bj;
	}
}

int	render_map(t_data *data)
{
	t_minimap_info	c;
	int				bi;

	minimap_prepare(&c, data);
	bi = c.i0;
	while (bi <= c.i1)
	{
		minimap_render_column(&c, bi);
		++bi;
	}
	return (0);
}
