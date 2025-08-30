/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewirte_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:02:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 11:32:30 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_mlx_get_data_addr(t_img_data *d)
{
	return (mlx_get_data_addr(d->img, &d->bpp, &d->ll, &d->endian));
}

void	ft_put_pixel(t_img_data img, t_cor cor, int color)
{
	char	*dst;

	dst = img.addr + (int)cor.y * img.ll + (int)cor.x * (img.bpp / 8);
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_pixel(t_img_data *img, int x, int y)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	if (x >= img->w)
		x = img->w - 1;
	if (y >= img->h)
		y = img->h - 1;
	dst = img->addr + y * img->ll + x * (img->bpp / 8);
	return (*(unsigned int *)dst);
}

/*
 * Draw `src` into `dst` at (params.x,
	params.y) scaled to (params.w x params.h).
 * Uses nearest-neighbour sampling and skips transparent pixels.
 */
void	ft_mlx_put_image(t_img_data *dst, t_img_data *src, t_put_params params)
{
	unsigned int	color;

	int (dx), (dy), (sx), (sy), (px), (py);
	if (!dst || !src || params.w <= 0 || params.h <= 0)
		return ;
	dy = -1;
	while (++dy < params.h)
	{
		sy = (dy * src->h) / params.h;
		dx = -1;
		while (++dx < params.w)
		{
			sx = (dx * src->w) / params.w;
			color = ft_get_pixel(src, sx, sy);
			if (color != 0x00000000 && color != 0xFF000000)
			{
				px = params.x + dx;
				py = params.y + dy;
				if (px >= 0 && px < dst->w && py >= 0 && py < dst->h)
					ft_put_pixel(*dst, (t_cor){px, py}, color);
			}
		}
	}
}
