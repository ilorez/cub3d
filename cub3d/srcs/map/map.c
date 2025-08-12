/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:13 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/12 12:25:06 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/utils.h"


int render_checked_map_rect(t_img_data img, int color, int size, t_cor pos)
{
  t_cor cor;
  double y;

	cor.x = pos.x;
  y = pos.y;
  if (cor.x < 0)
    cor.x = 0;
  if (y < 0)
    y = 0;
  if (y > MAP_SIZE)
    y = MAP_SIZE;

	while (cor.x < pos.x + size)
	{
    if (cor.x >= MAP_SIZE)
      break;
		cor.y = y;
		while (cor.y < pos.y + size)
    {
      if (cor.y >= MAP_SIZE)
        break;
      ft_put_pixel(img, cor, color);
      cor.y++;
    }
		++(cor.x);
	}
	return (0);
}

int is_wall2(t_cor *pos, t_data *data)
{
  int i,j;

  i = (pos->x) / BLOCK_SIZE;
  j = (pos->y) / BLOCK_SIZE;
  //if (i < 0)
   // pos->x = 0;
  //if (j < 0)
  //  pos->y = 0;
  //if (pos->x >= WIN_WIDTH)
  //  pos->x = WIN_WIDTH - 1;
  //if (pos->y >= WIN_HEIGHT)
  //  pos->y = WIN_HEIGHT - 1;
  //if (i >= data->map->columns || j >= data->map->rows || i <= 0 || j <= 0)
   // return (1);
  printf("is wall: i: %d, j: %d\n", i,j);
  if (i >= data->map->rows-1 || j >= data->map->columns-1)
    return (0);
  if ((data->map->arr)[j][i])
    return 1;
  return 0;
}

int render_map(t_data *data, t_map *map)
{
  double imgi,imgj, arri, arrj, tmpj;
  t_cor pos;
  t_cercl c;

  imgi = 0;
  imgj = 0;
  ft_bzero(map->data.addr, MAP_SIZE * MAP_SIZE * (map->data.bpp / 8));
  arri = data->p.pos.x - MAP_SIZE/2.0;
  arrj = data->p.pos.y - MAP_SIZE/2.0;
  if (arri < 0)
    imgi = arri * -1;
  if (arrj < 0)
    imgj = arrj * -1;
  while (imgi < MAP_SIZE)
  {
    tmpj = imgj;
    while (tmpj < MAP_SIZE)
    {
      //printf("%f, %f\n", i, j);
      pos = (t_cor){imgi,tmpj};
      if (is_wall2(&(t_cor){arri + imgi, arrj+tmpj}, data))
        ft_put_pixel(map->data, pos, COLOR_WHITE);
      else
        ft_put_pixel(map->data, pos, COLOR_BLACK);
      tmpj++;
    }
    imgi++;
  }

  c.color = COLOR_RED;
  c.radius = 6;
  c.center = (t_cor){MAP_SIZE/2.0, MAP_SIZE/2.0};
  render_filled_cercle(map->data, c);
  return (0);
}

//int render_map(t_map *map)
//{
//  int i,j;
//  t_rect rect;
//
//  rect.width = map->bs;
//  rect.height = map->bs;
//  i = -1;
//  while (++i < map->columns)
//  {
//    j = -1;
//    while (++j < map->rows )
//    {
//      rect.pos.x = i * rect.width;
//      rect.pos.y = j * rect.height;
//      if (map->arr[j][i])
//      {
//        rect.color = COLOR_WHITE;
//        render_rect(map->data, rect);
//      }
//      else
//      {
//        rect.color = COLOR_BLACK;
//        render_rect(map->data, rect);
//      }
//    }
//  }
//  return (0);
//}
