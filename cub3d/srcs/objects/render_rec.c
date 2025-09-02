/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/16 12:00:12 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

int	render_rect(t_img_data img, t_rect r)
{
	int (x), (y), (x0), (x1), (y0), (y1);
	x0 = r.pos.x;
	if (r.pos.x < 0)
		x0 = 0;
	x1 = r.pos.x + r.width;
	if (x1 > WIN_WIDTH)
		x1 = WIN_WIDTH;
	y0 = r.pos.y;
	if (r.pos.y < 0)
		y0 = 0;
	y1 = r.pos.y + r.height;
	if (y1 > WIN_HEIGHT)
		y1 = WIN_HEIGHT;
	x = x0 - 1;
	while (++x < x1)
	{
		y = y0 - 1;
		while (++y < y1)
			ft_put_pixel(img, (t_cor){(double)x, (double)y}, r.color);
	}
	return (0);
}
