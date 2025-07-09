/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:36:13 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 12:02:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/utils.h"

int render_map(t_img_data img, t_map *map)
{
  int i,j;
  t_rect rect;

  // change bg
  rect.color = COLOR_BLUE;
  rect.pos.x = 0;
  rect.pos.y = 0;
  rect.height = MAX_MAP_HEIGHT;
  rect.width = MAX_MAP_WIDTH;
  render_rect(img, rect);
  rect.color = COLOR_WHITE;
  rect.width = 50;
  rect.height = 50;
  i = -1;
  while (++i < map->columns )
  {
    j = -1;
    while (++j < map->rows )
    {
      if (map->arr[j][i])
      {
        rect.pos.x = i * rect.width;
        rect.pos.y = j * rect.height;
        render_rect(img, rect);
      }
    }
  }
  return (0);
}
