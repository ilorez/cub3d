/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:39:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/04 10:35:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

//// Bresenham's line algorithm for integer points
//void render_line(t_img_data img, t_line *line)
//{
//    int dx, dy, sx,sy,err,x,y, e2; 
//    dx = line->e.x - line->s.x;
//    dy = line->e.y - line->s.y;
//    sx = (line->s.x < line->e.x) ? 1 : -1;
//    sy = (line->s.y < line->e.y) ? 1 : -1;
//    err = dx - dy;
//    x = line->s.x;
//    y = line->s.y;
//
//    while (1)
//    {
//        ft_put_pixel(img, (t_cor){x, y}, line->color);
//        if (x > (int)(int)line->e.x)
//            x = (int)(int)line->e.x;
//        if (y > (int)(int)line->e.y)
//            y = (int)(int)line->e.y;
//        if (x == (int)line->e.x && y == (int)line->e.y)
//            break;
//        e2 = 2 * err;
//        if (e2 > -dy)
//        {
//            err -= dy;
//            x += sx;
//        }
//        if (e2 < dx)
//        {
//            err += dx;
//            y += sy;
//        }
//    }
//}

// DDA algo
void render_line(t_img_data img, t_line *line)
{
	double dx = line->e.x - line->s.x;
	double dy = line->e.y - line->s.y;

	double steps = fmax(fabs(dx), fabs(dy)); // max of |dx| and |dy|
  if (steps == 0)
    return;
	double x_inc = dx / steps;
	double y_inc = dy / steps;
	double x = line->s.x;
	double y = line->s.y;

	for (int i = 0; i <= steps; i++)
	{
		t_cor cor = { round(x), round(y) };
		ft_put_pixel(img, cor, line->color);
		x += x_inc;
		y += y_inc;
	}
}
