/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 11:39:38 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/03 13:40:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

// Bresenham's line algorithm for integer points
void render_line(t_img_data img, t_line *line)
{
    int dx, dy, sx,sy,err,x,y, e2; 
    dx = abs((int)(line->e.x - line->s.x));
    dy = abs((int)(line->e.y - line->s.y));
    sx = (line->s.x < line->e.x) ? 1 : -1;
    sy = (line->s.y < line->e.y) ? 1 : -1;
    err = dx - dy;
    x = line->s.x;
    y = line->s.y;

    while (1)
    {
        ft_put_pixel(img, (t_cor){x, y}, line->color);
        if (x == (int)line->e.x && y == (int)line->e.y)
            break;
        e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

