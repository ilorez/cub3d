/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:11:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/03 13:55:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"
#include <math.h>

void render_player(t_data *data)
{
  t_cercl cercl;
  t_line line;

  cercl.center = data->p.pos;
  cercl.radius = data->p.size;
  cercl.color = PLAYER_COLOR;
  render_filled_cercle(data->map->data, cercl);
  line.color = COLOR_RED;
  line.s = cercl.center;
  line.e.x = line.s.x + cos(data->p.angle) * data->map->block_size/2;
  line.e.y = line.s.y + sin(data->p.angle) * data->map->block_size/2;
  printf("endx: %f\n endy: %f\n", line.e.x, line.e.y);
  render_line(data->map->data, &line);
}


