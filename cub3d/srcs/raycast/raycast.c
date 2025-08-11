/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/09 10:01:01 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../../includes/raycast.h"

void draw_wall_cl(t_data *data, t_ray r, int cl, int color, double ray_angl)
{
  t_rect wall;
  double fixed_fish_eye_efect;
  double dst_prj_pln;

  fixed_fish_eye_efect = sqrt(r.dist )  * ZOOM * cos( ray_angl - data->p.angle);
  dst_prj_pln = ((WIN_WIDTH / 2.0) / (tan(FOV / 2.0)));
  wall.height = (data->map->bs / fixed_fish_eye_efect) * dst_prj_pln;
  wall.width = RAY_WIDTH;
  wall.color = ft_degree_color(fixed_fish_eye_efect, color);
  wall.pos.x = cl * RAY_WIDTH; 
  wall.pos.y = data->p.pitch - (wall.height / 2.0); 
  render_rect(data->img, wall);
};

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
    raycast_cl(data, angle_inc, i);
    angle_inc += ANGLE_INC;
  }
}

// cast column
void raycast_cl(t_data *data, double ray_angl, int cl)
{
  t_line line;
  t_ray rh;
  t_ray rv;
  int dh; // if the ray facing the down it's 1, if up its -1 
  int dv; // if the ray facing the right it's 1, if up its -1

  
  dh = -1;
  if (ray_angl < PI)
    dh = 1;
  dv = -1;
  if (ray_angl < 0.5 * PI || ray_angl > 1.5 * PI)
    dv = 1;
  line.color = 0x00FF00;
  line.s = data->p.pos;
  rv = vertical_check(data, ray_angl, dv);
  rh = horizontal_check(data, ray_angl, dh, dv);
  if (rh.dist < rv.dist)
  {
    line.e = rh.hit;
    draw_wall_cl(data, rh, cl, COLOR_YELLOW, ray_angl);
  }
  else
  {
    line.e = rv.hit;
    draw_wall_cl(data, rv, cl, COLOR_BLUE, ray_angl);
  }
  render_line(data->map->data, &line);
}
