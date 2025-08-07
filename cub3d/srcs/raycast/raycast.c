/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/07 17:19:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../../includes/raycast.h"

// go in all column and cast them
void raycast(t_data *data)
{
  int i;
  double angle_inc;

  i = -1;
  angle_inc = data->p.angle - FOV / 2;
  while (++i < RAY_NUM)
  {
    if (angle_inc > 2*PI)
      angle_inc -= 2*PI;
    else if (angle_inc < 0)
      angle_inc += 2*PI;
    raycast_cl(data, angle_inc);
    angle_inc += ANGLE_INC;
  }
}

// cast column
void raycast_cl(t_data *data, double ray_angl)
{
  t_line line;
  t_ray r;

  r.dh = -1;
  if (ray_angl < PI)
    r.dh = 1;
  r.dv = -1;
  if (ray_angl < 0.5 * PI || ray_angl > 1.5 * PI)
    r.dv = 1;
  line.color = 0x00FF00;
  line.s = data->p.pos;
  r = vertical_check(data, ray_angl, r);
  r = horizontal_check(data, ray_angl, r);
  if (r.distv == -1.0)
    line.e = r.hith;
  else if (r.disth == -1.0)
    line.e = r.hitv;
  else if (r.disth < r.distv)
    line.e = r.hith;
  else
    line.e = r.hitv;
  render_line(data->map->data, &line);
}
