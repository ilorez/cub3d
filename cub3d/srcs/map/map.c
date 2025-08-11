/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:13 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/03 10:18:33 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/utils.h"

int render_map(t_map *map)
{
  int i,j;
  t_rect rect;

  rect.width = map->bs;
  rect.height = map->bs;
  i = -1;
  while (++i < map->columns)
  {
    j = -1;
    while (++j < map->rows )
    {
      rect.pos.x = i * rect.width;
      rect.pos.y = j * rect.height;
      if (map->arr[j][i])
      {
        rect.color = COLOR_WHITE;
        render_rect(map->data, rect);
      }
      else
      {
        rect.color = COLOR_BLACK;
        render_rect(map->data, rect);
      }
    }
  }
  return (0);
}
