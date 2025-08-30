/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 10:39:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"

// void	draw_wall_cl(t_data *data, t_ray r, int cl, double ray_angl);
static void		draw_wall_cl(t_data *d, t_ray r, int cl);
static void		raycast_cl(t_data *data, t_raycl_args a);

// go in all column and cast them
void	raycast(t_data *data)
{
	int				ray_num;
	t_raycl_args	args;

	args.hskip = 0;
	args.vskip = 0;
	args.cl = -1;
	args.ang = data->p.angle - FOV / 2;
	ray_num = WIN_WIDTH / RAY_WIDTH;
	while (++args.cl < ray_num)
	{
		if (args.ang > 2 * PI)
			args.ang -= 2 * PI;
		else if (args.ang < 0)
			args.ang += 2 * PI;
		args.dh = -1;
		if (args.ang < PI)
			args.dh = 1;
		args.dv = -1;
		if (args.ang < 0.5 * PI || args.ang > 1.5 * PI)
			args.dv = 1;
		raycast_cl(data, args);
		args.ang += FOV / ray_num;
	}
}

// cast column
// int dh; // if the ray facing the down it's 1, if up its -1
// int dv; // if the ray facing the right it's 1, if up its -1
static void	raycast_cl(t_data *data, t_raycl_args a)
{
	t_ray	nearest;

	a.rv = vertical_check(data, a);
	a.rh = horizontal_check(data, a);
	a.rh.color = COLOR_YELLOW;
	a.rv.color = COLOR_BLUE;
	if (a.rh.dist < a.rv.dist)
	{
		if (a.rh.type == BLK_DOOR)
			a.hskip++;
		nearest = a.rh;
	}
	else
	{
		if (a.rv.type == BLK_DOOR)
			a.vskip++;
		nearest = a.rv;
	}
	nearest.ang = a.ang;
	if (nearest.type == BLK_DOOR)
		raycast_cl(data, a);
	draw_wall_cl(data, nearest, a.cl);
}

t_rect	get_wall_rect(t_data *data, t_ray r, int cl, double ray_angl)
{
	t_rect	wall;
	double	fixed_fish_eye_efect;
	double	dst_prj_pln;

	fixed_fish_eye_efect = sqrt(r.dist) * ZOOM * cos(ray_angl - data->p.angle);
	dst_prj_pln = ((WIN_WIDTH / 2.0) / (tan(FOV / 2.0)));
	wall.height = (BLOCK_SIZE / fixed_fish_eye_efect) * dst_prj_pln;
	wall.width = RAY_WIDTH;
	wall.pos.x = cl * RAY_WIDTH;
	wall.pos.y = data->p.pitch - (wall.height / 2.0);
	wall.color = r.color;
	return (wall);
}

static t_cor	get_correct_hit(t_cor hit, double ray_angl)
{
	t_cor	correct_hit;

	correct_hit = hit;
	if (ray_angl > PI)
		correct_hit.y -= 0.000001;
	if (ray_angl > 0.5 * PI && ray_angl < 1.5 * PI)
		correct_hit.x -= 0.000001;
	return (correct_hit);
}

// side == 1 -> verticall
static void	draw_wall_cl(t_data *d, t_ray r, int cl)
{
	t_tex	*tex;

	if (is_door(get_correct_hit(r.hit, r.ang), d))
	{
		r.color = DOOR_COLOR;
		tex = &d->tex[TEX_DOOR];
	}
	else if (r.side == 0)
	{
		if (r.ang < M_PI)
			tex = &d->tex[TEX_SO];
		else
			tex = &d->tex[TEX_NO];
	}
	else
	{
		if (r.ang < 0.5 * M_PI || r.ang > 1.5 * M_PI)
			tex = &d->tex[TEX_EA];
		else
			tex = &d->tex[TEX_WE];
	}
	if (tex && tex->loaded)
		draw_wall_texture(d, r, cl, tex);
	else
		render_rect(d->img, get_wall_rect(d, r, cl, r.ang));
}
