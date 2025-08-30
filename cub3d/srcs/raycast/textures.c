/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:16:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 10:40:55 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/raycast.h"

static void	clamp_vertical(t_rect wall, int *scr_top, int *scr_bottom)
{
	*scr_top = (int)wall.pos.y;
	*scr_bottom = (int)ceil(wall.pos.y + wall.height);
	if (*scr_top < 0)
		*scr_top = 0;
	if (*scr_bottom > WIN_HEIGHT)
		*scr_bottom = WIN_HEIGHT;
}

// side == 1 => ver in map
// get tex_x which is the column x that we will draw from the img
// and flip it in west and south dir
static int	get_tex_x(t_ray r, t_tex *tex, double ray_angl)
{
	double	fract;
	int		tex_x;

	if (r.side == 1)
		fract = fmod(r.hit.y, BLOCK_SIZE) / (double)BLOCK_SIZE;
	else
		fract = fmod(r.hit.x, BLOCK_SIZE) / (double)BLOCK_SIZE;
	if (fract < 0)
		fract += 1.0;
	tex_x = (int)(fract * (double)tex->img.w);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex->img.w)
		tex_x = tex->img.w - 1;
	if (r.side == 0 && ray_angl < M_PI)
		tex_x = tex->img.w - tex_x - 1;
	if (r.side == 1 && ray_angl > 0.5 * M_PI && ray_angl < 1.5 * M_PI)
		tex_x = tex->img.w - tex_x - 1;
	return (tex_x);
}

static void	draw_column(t_data *data, t_tex *tex, t_rect wall, int tex_x)
{
	unsigned int	color;

	int (ty), (screen_y);
	double (step), (tex_y) = 0.0;
	step = (double)tex->img.h / wall.height;
	screen_y = (int)wall.pos.y;
	if (screen_y < 0)
	{
		tex_y += (step * (int)screen_y * -1);
		screen_y = 0;
	}
	while (screen_y < (int)(wall.pos.y + wall.height) && screen_y < WIN_HEIGHT)
	{
		ty = (int)tex_y;
		if (ty < 0)
			ty = 0;
		if (ty >= tex->img.h)
			ty = tex->img.h - 1;
		color = ft_get_pixel(&tex->img, tex_x, ty);
		if (color != 0x00000000 && color != 0xFF000000)
			ft_put_pixel(data->img, (t_cor){(int)wall.pos.x, screen_y}, color);
		tex_y += step;
		screen_y++;
	}
}

void	draw_wall_texture(t_data *data, t_ray r, int cl, t_tex *tex)
{
	t_rect	wall;
	int		scr_top;
	int		scr_bottom;
	int		tex_x;

	wall = get_wall_rect(data, r, cl, r.ang);
	clamp_vertical(wall, &scr_top, &scr_bottom);
	tex_x = get_tex_x(r, tex, r.ang);
	draw_column(data, tex, wall, tex_x);
}
