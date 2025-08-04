/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:11:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/04 15:55:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include <math.h>

// translate x,y to map grid and see if it inside walls
int ft_is_valid_pos(t_cor pos, t_data *data)
{
  int i,j;

  i = (pos.x)/ data->map->block_size;
  j = (pos.y)/ data->map->block_size;
  if ((data->map->arr)[j][i])
    return 0;
  return 1;
}

void update_player_pos(t_data *data)
{
  t_cor nextPos;
  //printf("dx:%d, \ndy:%d\n", data->p.dx, data->p.dy);
  // move player
  if (data->p.dy)
  {
    nextPos.x = data->p.pos.x +  data->p.speed * cos(data->p.angle) * data->p.dy;
    nextPos.y = data->p.pos.y + data->p.speed * sin(data->p.angle) * data->p.dy;
    if (ft_is_valid_pos(nextPos, data))
      data->p.pos = nextPos;
  }
  if (data->p.dx)
    data->p.angle += data->p.rs * data->p.dx;
}

void render_player(t_data *data)
{
  t_cercl cercl;
  t_line line;

  update_player_pos(data);
  cercl.center = data->p.pos;
  cercl.radius = data->p.size;
  cercl.color = PLAYER_COLOR;
  render_filled_cercle(data->map->data, cercl);
  line.color = COLOR_RED;
  line.s = cercl.center;
  line.e.x = line.s.x + cos(data->p.angle) * data->map->block_size/2;
  line.e.y = line.s.y + sin(data->p.angle) * data->map->block_size/2;
  //printf("endx: %f\n endy: %f\n", line.e.x, line.e.y);
  render_line(data->map->data, &line);
}


