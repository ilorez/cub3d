/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 17:13:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 10:14:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"

// it's require to use sqrt, if u don't need real destance
int	is_inlimit(t_cor f, t_data *data)
{
	return (f.x >= 0 && f.x < (BLOCK_SIZE * data->map->columns) && f.y >= 0
		&& f.y < (BLOCK_SIZE * data->map->rows));
}

double	get_distance(t_cor a, t_cor b)
{
	double	db;

	db = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	return (db);
}

t_ray	horizontal_check(t_data *data, t_raycl_args a)
{
	t_cor	first;
	t_cor	step;
	t_ray	r;

	r.side = 0;
	first.y = floor(data->p.pos.y / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE
		* (a.dh == 1);
	first.x = data->p.pos.x + (first.y - data->p.pos.y) / tan(a.ang);
	step.y = BLOCK_SIZE * a.dh;
	step.x = a.dv * fabs(step.y / tan(a.ang));
	while (is_inlimit(first, data))
	{
		r.type = is_wall(&((t_cor){first.x, first.y + a.dh}), data);
		if (r.type && !a.hskip--)
		{
			r.hit = first;
			r.dist = get_distance(data->p.pos, first);
			return (r);
		}
		first = (t_cor){first.x + step.x, first.y + step.y};
	}
	r.dist = MAX_DISTANCE;
	return (r);
}

// we using v/hskip for skip founded doors in hor/ver lines
t_ray	vertical_check(t_data *data, t_raycl_args a)
{
	t_cor	first;
	t_cor	step;
	t_ray	r;

	r.side = 1;
	first.x = floor(data->p.pos.x / BLOCK_SIZE) * BLOCK_SIZE + BLOCK_SIZE
		* (a.dv == 1);
	first.y = data->p.pos.y + ((first.x - data->p.pos.x) * tan(a.ang));
	step.x = BLOCK_SIZE * a.dv;
	step.y = step.x * tan(a.ang);
	while (is_inlimit(first, data))
	{
		r.type = is_wall(&((t_cor){first.x + a.dv, first.y}), data);
		if (r.type && !a.vskip--)
		{
			r.hit = first;
			r.dist = get_distance(data->p.pos, first);
			return (r);
		}
		first = (t_cor){first.x + step.x, first.y + step.y};
	}
	r.dist = MAX_DISTANCE;
	return (r);
}
