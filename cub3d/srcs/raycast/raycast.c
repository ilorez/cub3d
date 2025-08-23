/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:55:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/23 11:09:37 by znajdaou         ###   ########.fr       */
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


//void draw_rect_texture(t_data *data, t_rect r, t_tex tex)
//{
//  double x_per, y_per;
//  double wall_w, wall_h; int xi, yi;
//  int i = -1;
//  int j;
//  // while in from x to x+Width and from y to y+height
//  // get xi/yi color from image
//  // put in xi/yi in wall
//  //
//  // how to translate x,y of columns to x,y of image
//  x_per = (r.pos.x - floor(r.pos.x))/BLOCK_SIZE;// get the from 0 to 1, this result we will multiplay it by tex_w to get real x
//  y_per = 
//  while (++i < r.width)
//  {
//    j = -1;
//    while (++j < r.height)
//    {
//      xi = i + tex.img.w * x_per;
//      yi = j * tex.img.h /
//      
//
//    }
//  }
//  
//
//}
void draw_wall_cl(t_data *m, t_ray r, int cl, double ray_angl)
{
    /* choose texture based on wall orientation / which side of block (you may want
       to pick based on the grid cell content too). I’ll pick using r.color for demo,
       but better: use map grid cell value at r.hit to know which face texture to use. */

    t_tex *tex = NULL;
    /* Example mapping: if you stored wall side info elsewhere map_info->tex[TEX_NO] etc:
       choose one depending on hit side and ray direction - adapt to your map's orientation */
    if (r.side == 0) /* horizontal wall */
    {
        /* choose between SO / NO depending on ray direction.
           If ray facing down (dh == 1) pick SO else NO.
           But we don't have dh here — infer from ray_angl: */
        if (ray_angl < M_PI) /* facing down (0..PI) */
            tex = &m->tex[TEX_SO];
        else
            tex = &m->tex[TEX_NO];
    }
    else /* vertical wall */
    {
        if (ray_angl < 0.5 * M_PI || ray_angl > 1.5 * M_PI) /* facing right */
            tex = &m->tex[TEX_EA];
        else
            tex = &m->tex[TEX_WE];
    }

    if (tex && tex->loaded)
    {
        draw_wall_texture(m, r, cl, ray_angl, tex);
    }
    else
    {
        /* fallback to solid color rectangle (your original implementation) */
        t_rect wall;
        double fixed_fish_eye_efect;
        double dst_prj_pln;

        fixed_fish_eye_efect = sqrt(r.dist) * ZOOM * cos(ray_angl - m->p.angle);
        dst_prj_pln = ((WIN_WIDTH / 2.0) / (tan(FOV / 2.0)));
        wall.height = (BLOCK_SIZE / fixed_fish_eye_efect) * dst_prj_pln;
        wall.width = RAY_WIDTH;
        wall.color = ft_degree_color(fixed_fish_eye_efect, r.color);
        wall.pos.x = cl * RAY_WIDTH;
        wall.pos.y = m->p.pitch - (wall.height / 2.0);
        render_rect(m->img, wall);
    }
}

void	draw_wall_texture(t_data *data, t_ray r, int cl, double ray_angl, t_tex *tex)
{
	  t_rect wall;
    double fixed_fish_eye_efect;
    double dst_prj_pln;

    /* same height calc you used */
    fixed_fish_eye_efect = sqrt(r.dist) * ZOOM * cos(ray_angl - data->p.angle);
    dst_prj_pln = ((WIN_WIDTH / 2.0) / (tan(FOV / 2.0)));
    wall.height = (BLOCK_SIZE / fixed_fish_eye_efect) * dst_prj_pln;
    wall.width = RAY_WIDTH;
    wall.pos.x = cl * RAY_WIDTH;
    wall.pos.y = data->p.pitch - (wall.height / 2.0);

    /* clamp vertical draw */
    int scr_top = (int)wall.pos.y;
    int scr_bottom = (int)ceil(wall.pos.y + wall.height);
    if (scr_top < 0) scr_top = 0;
    if (scr_bottom > WIN_HEIGHT) scr_bottom = WIN_HEIGHT;

    /* compute texture X coordinate:
       use fractional position inside the BLOCK_SIZE tile.
       r.hit is in world coords (same units as BLOCK_SIZE). */
    double fract;
    if (r.side == 1) /* vertical hit -> use y fractional part */
        fract = fmod(r.hit.y, BLOCK_SIZE) / (double)BLOCK_SIZE;
    else /* horizontal hit -> use x fractional part */
        fract = fmod(r.hit.x, BLOCK_SIZE) / (double)BLOCK_SIZE;

    if (fract < 0) fract += 1.0; // safety
    int tex_x = (int)(fract * (double)tex->img.w);
    if (tex_x < 0) tex_x = 0;
    if (tex_x >= tex->img.w) tex_x = tex->img.w - 1;

    /* optional automatic flipping so textures face correctly:
       - if horizontal wall and ray is pointing left, flip
       - if vertical wall and ray is pointing up, flip
       tweak as needed for visual correctness */
    if (r.side == 0 && (ray_angl > M_PI)) tex_x = tex->img.w - tex_x - 1;
    if (r.side == 1 && (ray_angl > 0.5 * M_PI && ray_angl < 1.5 * M_PI)) tex_x = tex->img.w - tex_x - 1;

    /* draw each vertical pixel: nearest neighbor sampling */
    int col_x = (int)wall.pos.x;
    int wall_pixels = scr_bottom - scr_top;
    for (int py = 0; py < wall_pixels; ++py)
    {
        /* y in screen */
        int screen_y = scr_top + py;

        /* compute texture y: map py [0..wall.height) to [0..tex.h) */
        double tex_rel = (double)py / (double)wall.height;
        int tex_y = (int)(tex_rel * (double)tex->img.h);
        if (tex_y < 0) tex_y = 0;
        if (tex_y >= tex->img.h) tex_y = tex->img.h - 1;
        unsigned int color = ft_get_pixel(&tex->img, tex_x, tex_y);
        ft_put_pixel(data->img, (t_cor){col_x, screen_y}, color);
    }
}
