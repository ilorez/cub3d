/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:13:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/07 17:18:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/raycast.h"

//int is_b_nearer_than_c(t_cor a, t_cor b, t_cor c)
//{
//	double db = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
//	double dc = (c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y);
//	return (db < dc);
//}

int is_inlimit(t_cor f, t_data *data)
{
  return f.x >= 0 && f.x < data->map->width && f.y >= 0 && f.y < data->map->hieght;
}


double get_distance(t_cor a, t_cor b)
{
	double db = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	return (db);
}

t_ray horizontal_check(t_data *data, double ray_angl, t_ray r)
{
  t_cor first;
  t_cor step;

  first.y = floor(data->p.pos.y / data->map->bs) * data->map->bs + data->map->bs * (r.dh == 1); 
  first.x = data->p.pos.x + (first.y - data->p.pos.y) / tan(ray_angl);
  step.y = data->map->bs * r.dh;
  step.x = r.dv * fabs(step.y / tan(ray_angl));
  if (r.dh == -1)
    first.y--;
  while (is_inlimit(first, data))
  {
    if (is_wall(&(first), data))
    {
      r.hith = first;
      r.disth = get_distance(data->p.pos, first);
      return r;
    }
    first = (t_cor){first.x + step.x, first.y + step.y};
  }
  r.disth = -1;
  return (r);
}

t_ray vertical_check(t_data *data, double ray_angl, t_ray r)
{
  t_cor first;
  t_cor step;

  first.x = floor(data->p.pos.x / data->map->bs) * data->map->bs + data->map->bs * (r.dv == 1); 
  first.y = data->p.pos.y + ((first.x - data->p.pos.x) * tan(ray_angl));
  step.x = data->map->bs * r.dv;
  step.y = step.x * tan(ray_angl);
  if (r.dv == -1)
    first.x--;
  while (is_inlimit(first, data))
  {
    if (is_wall(&(first), data))
    {
      r.hitv = first;
      r.distv = get_distance(data->p.pos, first);
      return r;
    }
    first = (t_cor){first.x + step.x, first.y + step.y};
  }
  r.distv = -1;
  return (r);
}
