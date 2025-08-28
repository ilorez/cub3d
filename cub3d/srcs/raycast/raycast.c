/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/28 10:01:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"

//void	draw_wall_cl(t_data *data, t_ray r, int cl, double ray_angl);
void draw_wall_cl(t_data *m, t_ray r, int cl, double ray_angl);
// go in all column and cast them
void	raycast(t_data *data)
{
	int		i;
	int		ray_num;
	double	angle_inc;

	i = -1;
	angle_inc = data->p.angle - FOV / 2;
	ray_num = WIN_WIDTH / RAY_WIDTH;
	while (++i < ray_num)
	{
		if (angle_inc > 2 * PI)
			angle_inc -= 2 * PI;
		else if (angle_inc < 0)
			angle_inc += 2 * PI;
		raycast_cl(data, angle_inc, i, 0, 0);
		angle_inc += FOV / ray_num;
	}
}

// cast column
// int dh; // if the ray facing the down it's 1, if up its -1
// int dv; // if the ray facing the right it's 1, if up its -1
void	raycast_cl(t_data *data, double ray_angl, int cl, int vskip, int hskip)
{
	t_ray	rh;
	t_ray	rv;
  t_ray nearest;
	int		dh;
	int		dv;

	dh = -1;
	if (ray_angl < PI)
		dh = 1;
	dv = -1;
	if (ray_angl < 0.5 * PI || ray_angl > 1.5 * PI)
		dv = 1;
	rh.color = COLOR_YELLOW;
	rv.color = COLOR_BLUE;
	rv = vertical_check(data, ray_angl, dv, vskip);
	rh = horizontal_check(data, ray_angl, dh, dv, hskip);
	if (rh.dist < rv.dist)
  {
    if (rh.type == BLK_DOOR)
      hskip++;
    nearest = rh;
  }
	else
  {
    if (rv.type == BLK_DOOR)
      vskip++;
    nearest = rv;
  }
  if (nearest.type == BLK_WALL)
	  draw_wall_cl(data, nearest, cl, ray_angl);
  else if (nearest.type == BLK_DOOR)
  {
    raycast_cl(data, ray_angl, cl, vskip, hskip);
	  draw_wall_cl(data, nearest, cl, ray_angl);
  }
}

t_rect get_wall_rect(t_data *data, t_ray r, int cl, double ray_angl)
{
	  t_rect wall;
    double fixed_fish_eye_efect;
    double dst_prj_pln;

    fixed_fish_eye_efect = sqrt(r.dist) * ZOOM * cos(ray_angl - data->p.angle);
    dst_prj_pln = ((WIN_WIDTH / 2.0) / (tan(FOV / 2.0)));
    wall.height = (BLOCK_SIZE / fixed_fish_eye_efect) * dst_prj_pln;
    wall.width = RAY_WIDTH;
    wall.pos.x = cl * RAY_WIDTH;
    wall.pos.y = data->p.pitch - (wall.height / 2.0);
    wall.color = r.color;
    return (wall);
}

// side == 1 -> verticall
void draw_wall_cl(t_data *d, t_ray r, int cl, double ray_angl)
{
    t_tex *tex = NULL;
    t_cor correct_hit;

    correct_hit = r.hit;
    if (ray_angl > PI)
      correct_hit.y -= 0.000001;
    if (ray_angl > 0.5 * PI && ray_angl < 1.5 * PI)
      correct_hit.x -= 0.000001;
    //printf("(x,y)=> (%f, %f)\n", r.hit.x, r.hit.y);
    if (is_door(&correct_hit, d))
    {
        r.color = DOOR_COLOR;
        tex = &d->tex[TEX_DOOR];
    }
    else if (r.side == 0)
    {
        r.color = HOR_COLOR;
        if (ray_angl < M_PI)
            tex = &d->tex[TEX_SO];
        else
            tex = &d->tex[TEX_NO];
    }
    else
    {
        r.color = VER_COLOR;
        if (ray_angl < 0.5 * M_PI || ray_angl > 1.5 * M_PI)
            tex = &d->tex[TEX_EA];
        else
            tex = &d->tex[TEX_WE];
    }
    if (tex && tex->loaded)
        draw_wall_texture(d, r, cl, ray_angl, tex);
    else
        render_rect(d->img, get_wall_rect(d, r, cl, ray_angl));
}
