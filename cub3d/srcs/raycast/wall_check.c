/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:13:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/12 13:25:58 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/raycast.h"
#include <float.h>

//int is_b_nearer_than_c(t_cor a, t_cor b, t_cor c)
//{
//	double db = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
//	double dc = (c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y);
//	return (db < dc);
//}

int is_inlimit(t_cor f, t_data *data)
{
  return f.x >= 0 && f.x < (BLOCK_SIZE * data->map->columns) && f.y >= 0 && f.y < (BLOCK_SIZE * data->map->rows);
}


double get_distance(t_cor a, t_cor b)
{
	double db = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	return (db); // it's require to use sqrt, if u don't need real destance
}

t_ray horizontal_check(t_data *data, double ray_angl, int dh, int dv)
{
  t_cor first;
  t_cor step;
  t_ray r;

  first.y = floor(data->p.pos.y / BLOCK_SIZE) * data->map->bs + data->map->bs * (dh == 1); 
  first.x = data->p.pos.x + (first.y - data->p.pos.y) / tan(ray_angl);
  step.y = data->map->bs * dh;
  step.x = dv * fabs(step.y / tan(ray_angl));
  while (is_inlimit(first, data))
  {
    if (is_wall(&((t_cor){first.x, first.y + dh}), data))
    {
      r.hit = first;
      r.dist = get_distance(data->p.pos, first);
      return r;
    }
    first = (t_cor){first.x + step.x, first.y + step.y};
  }
  r.dist = MAX_DISTANCE;
  return (r);
}

t_ray vertical_check(t_data *data, double ray_angl, int dv)
{
  t_cor first;
  t_cor step;
  t_ray r;

  first.x = floor(data->p.pos.x / data->map->bs) * data->map->bs + data->map->bs * (dv == 1); 
  first.y = data->p.pos.y + ((first.x - data->p.pos.x) * tan(ray_angl));
  step.x = data->map->bs * dv;
  step.y = step.x * tan(ray_angl);
  while (is_inlimit(first, data))
  {
    if (is_wall(&((t_cor){first.x + dv, first.y}), data))
    {
      r.hit = first;
      r.dist = get_distance(data->p.pos, first);
      return r;
    }
    first = (t_cor){first.x + step.x, first.y + step.y};
  }
  r.dist = MAX_DISTANCE;
  return (r);
}
