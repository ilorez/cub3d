/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:11:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/12 12:04:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include <math.h>

void update_player_pos(t_data *data)
{
  t_cor nextPos;
  //printf("dx:%d, \ndy:%d\n", data->p.dx, data->p.dy);
  // move player
  if (data->p.dy)
  {
    nextPos.x = data->p.pos.x +  data->p.speed * data->delta_time * cos(data->p.angle) * data->p.dy;
    nextPos.y = data->p.pos.y + data->p.speed *  data->delta_time * sin(data->p.angle) * data->p.dy;
    if (!is_wall(&nextPos, data))
      data->p.pos = nextPos;
  }
  if (data->p.dh)
  {
    nextPos.x = data->p.pos.x +  data->p.speed * data->delta_time * cos(data->p.angle + (90 * PI / 180)) * data->p.dh;
    nextPos.y = data->p.pos.y + data->p.speed *  data->delta_time * sin(data->p.angle + (90 * PI / 180)) * data->p.dh;
    if (!is_wall(&nextPos, data))
      data->p.pos = nextPos;
  }
  if (data->p.dx)
  {
    data->p.angle += data->p.rs * data->delta_time * data->p.dx;
    data->p.angle = fmod(data->p.angle, 2 * PI);
    if (data->p.angle < 0)
      data->p.angle += (2 * PI);
    //printf("angle is: %f\n", data->p.angle);
  }
  if (data->p.dv)
  {
    data->p.pitch += MOV_PITCH_SPEED * data->delta_time * data->p.dv;
    if (data->p.pitch > WIN_HEIGHT)
        data->p.pitch = WIN_HEIGHT;
    else if (data->p.pitch < 0)
        data->p.pitch = 0;

  }
}

void render_player(t_data *data)
{
  t_cercl cercl;
  t_line line;

  update_player_pos(data);
  cercl.center = (t_cor){MAP_SIZE/2.0, MAP_SIZE/2.0};
  cercl.radius = 6;
  cercl.color = PLAYER_COLOR;
  render_filled_cercle(data->map->data, cercl);
  line.color = COLOR_RED;
  line.s = cercl.center;
  line.e.x = line.s.x + cos(data->p.angle) * BLOCK_SIZE/2;
  line.e.y = line.s.y + sin(data->p.angle) * BLOCK_SIZE/2;
  //printf("endx: %f\n endy: %f\n", line.e.x, line.e.y);
  render_line(data->map->data, &line);
  printf("Player : x: %f, y: %f\n", data->p.pos.x, data->p.pos.y);
}


