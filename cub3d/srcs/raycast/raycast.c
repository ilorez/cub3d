/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/06 13:11:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "../../includes/raycast.h"

typedef struct s_ray {

  t_cor collision_point;
} t_ray;

t_cor horizontal_check(t_data *data, double ray_angl)
{
  t_cor collision;
  t_cor step;
  int i;

  collision.x = floor(data->p.pos.x / data->map->block_size) * data->map->block_size; 
  collision.y = collision.x * tan(ray_angl);
  step.x = data->map->block_size;
  step.y = step.x * tan(ray_angl);
  i = -1;
  while (!is_wall(collision, data) && ++i < data->map->columns)
    collision = (t_cor){collision.x + step.x, collision.y + step.y};
  return (collision);
}


t_cor vertical_check(t_data *data, double ray_angl)
{
  t_cor collision;
  t_cor step;
  int i;

  collision.y = floor(data->p.pos.y / data->map->block_size) * data->map->block_size; 
  collision.x = collision.y / tan(ray_angl);
  step.y = data->map->block_size;
  step.x = step.y / tan(ray_angl);
  i = -1;
  while (!is_wall(collision, data) && ++i < data->map->rows)
    collision = (t_cor){collision.x + step.x, collision.y + step.y};
  return (collision);
}



int is_b_nearer_than_c(t_cor a, t_cor b, t_cor c)
{
	double db = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	double dc = (c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y);
	return (db < dc);
}


void raycast_cl(t_data *data, double ray_angl)
{
  t_line line;
  //t_cor ver;
  line.color = 0x0100FF00;
  line.s = data->p.pos;
  line.e.x = data->p.pos.x + cos(ray_angl) * 50 ; 
  line.e.y = data->p.pos.y + sin(ray_angl) * 50 ;
  //ver = vertical_check(data, ray_angl);
  line.e = horizontal_check(data, ray_angl);
  //if (is_b_nearer_than_c(line.s, ver, line.e))
  //  line.e = ver;
  render_line(data->map->data, &line);
}

void raycast(t_data *data)
{
  int i;
  double angle_inc;

  i = -1;
  angle_inc = data->p.angle; // - FOV / 2;
  while (++i < 1)
  {
    // cast column
    raycast_cl(data, angle_inc);
    angle_inc += ANGLE_INC;
  }
}
