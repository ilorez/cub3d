/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cercle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:54:01 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/16 11:54:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

// used [(cor.x-center.x)^2 + (cor.y-center.y)^2]
// used [(center.x + dx -center.x)^2 + (center.y
//                       + dy cor.y-center.y)^2]
// used [(dx)^2 + (dy)^2]
void	render_filled_cercle(t_img_data img, t_cercl c)
{
	t_cor	cor;
	int		dx;
	int		dy;

	dy = -c.radius;
	while (dy <= c.radius)
	{
		dx = -c.radius;
		while (dx <= c.radius)
		{
			if (dx * dx + dy * dy <= c.radius * c.radius)
			{
				cor.x = c.center.x + dx;
				cor.y = c.center.y + dy;
				ft_put_pixel(img, cor, c.color);
			}
			dx++;
		}
		dy++;
	}
}

void	render_cercle(t_img_data img, t_cercl c)
{
	t_cor	cor;
	double	angle;
	double	angle_increment;

	angle = 0;
	angle_increment = 1.0 / c.radius;
	while (angle < 2 * M_PI)
	{
		cor.x = c.center.x + (int)(c.radius * cos(angle));
		cor.y = c.center.y + (int)(c.radius * sin(angle));
		if (cor.x >= 0 && cor.x < WIN_WIDTH && cor.y >= 0 && cor.y < WIN_HEIGHT)
			ft_put_pixel(img, cor, c.color);
		angle += angle_increment;
	}
}
