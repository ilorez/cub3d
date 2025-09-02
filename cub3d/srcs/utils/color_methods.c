/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:44:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 12:50:08 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int	create_trgb(unsigned char t, unsigned char r, unsigned char g,
		unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	merge_t_color(t_color c)
{
	return (c.a << 24 | c.r << 16 | c.g << 8 | c.b);
}

t_color	extract_color(int trgb)
{
	t_color	c;

	c.a = (trgb >> 24) & 0xFF;
	c.r = (trgb >> 16) & 0xFF;
	c.g = (trgb >> 8) & 0xFF;
	c.b = trgb & 0xFF;
	return (c);
}

int	ft_degree_color(double dist, int color)
{
	double	factor;
	t_color	base;
	t_color	shaded;
	int		max_dist;

	base = extract_color(color);
	max_dist = WIN_HEIGHT * 5;
	if (dist < 0)
		dist = 0;
	if (dist > max_dist)
		dist = max_dist;
	factor = 1.0 - (dist / max_dist);
	shaded.r = base.r * factor;
	shaded.g = base.g * factor;
	shaded.b = base.b * factor;
	shaded.a = base.a;
	return (create_trgb(shaded.a, shaded.r, shaded.g, shaded.b));
}
