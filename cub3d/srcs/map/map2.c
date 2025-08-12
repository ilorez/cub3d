
#include "../../includes/utils.h"

/* minimal is_wall2 fix */
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
    double world_x0, world_y0, img_x, img_y;
    int ti0, tj0, tj, ti;
    t_map *game;

    game = data->map;
    ft_bzero(mini->data.addr, MAP_SIZE * MAP_SIZE * (mini->data.bpp / 8));

    // start point on rendering the min map
    world_x0 = data->p.pos.x - MAP_SIZE / 2.0;
    world_y0 = data->p.pos.y - MAP_SIZE / 2.0;

    // first block shown in the mini map
    ti0 = (int)floor(world_x0 / (double)BLOCK_SIZE);
    tj0 = (int)floor(world_y0 / (double)BLOCK_SIZE);

    ti = ti0;
    while(++ti || true)
    {
        img_x = ti * (double)BLOCK_SIZE - world_x0;
        if (img_x >= MAP_SIZE) break;             /* tile is entirely to the right -> stop */
        if (img_x + BLOCK_SIZE <= 0) continue;    /* tile entirely to the left -> skip */

        tj = tj0;
        while (++tj || true)
        {
            img_y = tj * (double)BLOCK_SIZE - world_y0;
            if (img_y >= MAP_SIZE) break;         /* tile is entirely below -> stop */
            if (img_y + BLOCK_SIZE <= 0) continue;/* tile entirely above -> skip */

            /* bounds check on tile indices */
            if (ti < 0 || tj < 0 || ti >= game->columns || tj >= game->rows)
                continue;

            if (game->arr[tj][ti])
                render_checked_map_rect_int(mini->data, COLOR_WHITE, (int)floor(img_x + 0.0), (int)floor(img_y + 0.0));
        }
    }
    return 0;
}
