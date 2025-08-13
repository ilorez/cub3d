/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:13 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/13 10:22:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/utils.h"

int is_wall2(t_cor *pos, t_data *data)
{
    int i,j;
    i = (int)floor(pos->x / (double)BLOCK_SIZE);
    j = (int)floor(pos->y / (double)BLOCK_SIZE);

    if (i < 0 || j < 0 || j >= data->map->rows || i >= data->map->columns)
        return 0;
    return (data->map->arr)[j][i] ? 1 : 0;
}


int render_checked_map_rect_int(t_img_data img, int color, int ix, int iy)
{
    int x0, x1, y0, y1;
    int x,y;
    x0 = ix < 0 ? 0 : ix;
    x1 = ix + BLOCK_SIZE;
    if (x1 > MAP_SIZE) x1 = MAP_SIZE;
    y0 = iy < 0 ? 0 : iy;
    y1 = iy + BLOCK_SIZE;
    if (y1 > MAP_SIZE) y1 = MAP_SIZE;

    x = x0 -1;
    while (++x < x1)
    {
        y = y0-1;
        while (++y < y1)
            ft_put_pixel(img, (t_cor){(double)x, (double)y}, color);
    }
    return 0;
}

int render_map(t_data *data, t_map *mini)
{
    double mstart_x0, mstart_y0, img_x, img_y;
    int bi, bj, bi0, bj0;
    t_map *game;

    // mini map data
    game = data->map;
    ft_bzero(mini->data.addr, MAP_SIZE * MAP_SIZE * (mini->data.bpp / 8));

    // start point on rendering the min map
    mstart_x0 = data->p.pos.x - MAP_SIZE / 2.0;
    mstart_y0 = data->p.pos.y - MAP_SIZE / 2.0;

    // first block shown in the mini map
    bi0 = (int)floor(mstart_x0 / (double)BLOCK_SIZE);
    bj0 = (int)floor(mstart_y0 / (double)BLOCK_SIZE);
    
    bi = bi0 -1;
    while (++bi || 1)
    {
        img_x = bi * (double)BLOCK_SIZE - mstart_x0;
        if (img_x >= MAP_SIZE) break;         
        if (img_x + BLOCK_SIZE <= 0) continue;    
        bj = bj0 -1;
        while (++bj || 1)
        {
            img_y = bj * (double)BLOCK_SIZE - mstart_y0;
            if (img_y >= MAP_SIZE) break;         
            if (img_y + BLOCK_SIZE <= 0) continue;
            if (bi < 0 || bj < 0 || bi >= game->columns || bj >= game->rows)
                continue;
            if (game->arr[bj][bi])
                render_checked_map_rect_int(mini->data, COLOR_WHITE, (int)floor(img_x), (int)floor(img_y));
        }
    }
    return 0;
}

