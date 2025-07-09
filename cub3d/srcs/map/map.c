/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:13 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 21:11:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/utils.h"

int render_map(t_map *map)
{
  int i,j;
  t_rect rect;

  // change bg
  rect.color = COLOR_BLACK;
  rect.pos.x = 0;
  rect.pos.y = 0;
  rect.height = map->hieght;
  rect.width = map->width;
  render_rect(map->data, rect);
  rect.color = COLOR_WHITE;
  rect.width = map->block_size;
  rect.height = map->block_size;
  i = -1;
  while (++i < map->columns)
  {
    j = -1;
    while (++j < map->rows )
    {
      if (map->arr[j][i])
      {
        rect.pos.x = i * rect.width;
        rect.pos.y = j * rect.height;
        render_rect(map->data, rect);
      }
    }
  }
  return (0);
}
