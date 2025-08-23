/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/23 13:33:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"

//void	draw_wall_cl(t_data *data, t_ray r, int cl, double ray_angl);
void draw_wall_cl(t_data *m, t_ray r, int cl, double ray_angl);
void	draw_wall_texture(t_data *data, t_ray r, int cl, double ray_angl, t_tex *tex);

inline unsigned int ft_get_pixel(t_img_data *img, int x, int y)
{
    if (x < 0) x = 0;
    if (y < 0) y = 0;
    if (x >= img->w) x = img->w - 1;
    if (y >= img->h) y = img->h - 1;

    char *dst = img->addr + y * img->ll + x * (img->bpp / 8);
    return *(unsigned int *)dst;
}
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
		raycast_cl(data, angle_inc, i);
		angle_inc += FOV / ray_num;
	}
}

// cast column
// int dh; // if the ray facing the down it's 1, if up its -1
// int dv; // if the ray facing the right it's 1, if up its -1
void	raycast_cl(t_data *data, double ray_angl, int cl)
{
	t_ray	rh;
	t_ray	rv;
	int		dh;
	int		dv;

	dh = -1;
	if (ray_angl < PI)
		dh = 1;
	dv = -1;
	if (ray_angl < 0.5 * PI || ray_angl > 1.5 * PI)
		dv = 1;
	rv = vertical_check(data, ray_angl, dv);
	rh = horizontal_check(data, ray_angl, dh, dv);
	rh.color = COLOR_YELLOW;
	rv.color = COLOR_BLUE;
	if (rh.dist < rv.dist)
		draw_wall_cl(data, rh, cl, ray_angl);
	else
		draw_wall_cl(data, rv, cl, ray_angl);
}

inline t_rect get_wall_rect(t_data *data, t_ray r, int cl, double ray_angl)
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
    return (wall);
}

void draw_wall_cl(t_data *d, t_ray r, int cl, double ray_angl)
{
    t_tex *tex = NULL;

    if (r.side == 0)//horizontal
    {
        if (ray_angl < M_PI)//down
            tex = &d->tex[TEX_SO];
        else
            tex = &d->tex[TEX_NO];
    }
    else // vertical
    {
        if (ray_angl < 0.5 * M_PI || ray_angl > 1.5 * M_PI) // right
            tex = &d->tex[TEX_EA];
        else
            tex = &d->tex[TEX_WE];
    }
    if (tex && tex->loaded)
        draw_wall_texture(d, r, cl, ray_angl, tex);
    else
        render_rect(d->img, get_wall_rect(d, r, cl, ray_angl));
}



void	draw_wall_texture(t_data *data, t_ray r, int cl, double ray_angl, t_tex *tex)
{
    t_rect wall;
    wall = get_wall_rect(data, r, cl, ray_angl);
        /* clamp vertical draw */
    int scr_top = (int)wall.pos.y;
    int scr_bottom = (int)ceil(wall.pos.y + wall.height);
    if (scr_top < 0) scr_top = 0;
    if (scr_bottom > WIN_HEIGHT) scr_bottom = WIN_HEIGHT;

    // because r.hit is use same unit as BLOCK_SIZE, we get the persontage of the point in the block size and use persontage to get point in img
    double fract;
    if (r.side == 1)
        fract = fmod(r.hit.y, BLOCK_SIZE) / (double)BLOCK_SIZE;
    else 
        fract = fmod(r.hit.x, BLOCK_SIZE) / (double)BLOCK_SIZE;
    if (fract < 0) fract += 1.0;
    int tex_x = (int)(fract * (double)tex->img.w); // translate point
    if (tex_x < 0) tex_x = 0;
    if (tex_x >= tex->img.w) tex_x = tex->img.w - 1;

    /* optional automatic flipping so textures face correctly:
       - if horizontal wall and ray is pointing left, flip
       - if vertical wall and ray is pointing up, flip
       tweak as needed for visual correctness */
    //if (r.side == 0 && (ray_angl > M_PI))
    //  tex_x = tex->img.w - tex_x - 1;
    if (r.side == 1 && (ray_angl > 0.5 * M_PI && ray_angl < 1.5 * M_PI))
      tex_x = tex->img.w - tex_x - 1;
    
    double step = (double)tex->img.h / wall.height;
    double tex_pos = 0.0;
    if (scr_top == 0 && wall.pos.y < 0)
    {
        int skipped = (int)(-wall.pos.y);
        tex_pos = skipped * step;
    }

    int col_x = (int)wall.pos.x;
    double tex_y = tex_pos;
    for (int screen_y = scr_top; screen_y < scr_bottom; screen_y++)
    {
        int ty = (int)tex_y;
        if (ty < 0) ty = 0;
        if (ty >= tex->img.h) ty = tex->img.h - 1;
        unsigned int color = ft_get_pixel(&tex->img, tex_x, ty);
        ft_put_pixel(data->img, (t_cor){col_x, screen_y}, color);
    
        tex_y += step;
    }
}
