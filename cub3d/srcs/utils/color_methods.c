/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 11:44:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/11 14:33:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

int create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

t_color	extract_color(int trgb)
{
	t_color	c;

	c.a = (trgb >> 24) & 0xFF; // Transparency
	c.r = (trgb >> 16) & 0xFF; // Red
	c.g = (trgb >> 8) & 0xFF;  // Green
	c.b = trgb & 0xFF;         // Blue
	return (c);
}

/**
 * ft_degree_color - returns a faded color depending on distance
 * @dist: current distance
 * 
 * Closer = brighter, farther = darker.
 */
int	ft_degree_color(double dist, int color)
{
	double		factor;
	t_color		base;
	t_color		shaded;

  base = extract_color(color);

	// Clamp distance
	if (dist < 0)
		dist = 0;
	if (dist > REAL_MAX_DIST)
		dist = REAL_MAX_DIST;

	// 1.0 (close) -> 0.0 (far)
	factor = 1.0 - (dist / REAL_MAX_DIST);

	// Apply fade
	shaded.r = base.r * factor;
	shaded.g = base.g * factor;
	shaded.b = base.b * factor;
	shaded.a = base.a; // keep alpha as is

	return (create_trgb(shaded.a, shaded.r, shaded.g, shaded.b));
}

