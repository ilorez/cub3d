/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 13:06:48 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 10:34:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

static inline double	clampd(double v, double lo, double hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

static inline double	normalize_angle(double a)
{
	a = fmod(a, 2.0 * PI);
	if (a < 0.0)
		a += 2.0 * PI;
	return (a);
}

static inline void	try_move(t_data *data, double dx, double dy)
{
	double	step;
	double	len;
	int		steps;
	t_cor	delta_steps;

	step = 0.5;
	len = sqrt(dx * dx + dy * dy);
	steps = (int)(len / step);
	if (steps <= 0)
		steps = 1;
	delta_steps.x = dx / steps;
	delta_steps.y = dy / steps;
	while (steps--)
	{
		data->p.pos.x += delta_steps.x;
		if (is_wall(&data->p.pos, data))
			data->p.pos.x -= delta_steps.x;
		data->p.pos.y += delta_steps.y;
		if (is_wall(&data->p.pos, data))
			data->p.pos.y -= delta_steps.y;
	}
}

// --- movement: keyboard (W/S + A/D) ------------------------------------------
// forward/back: (cosA, sinA)
// rotate +90° => (-sinA, cosA)
void	handle_keyboard_move(t_data *data, double step, double cosA,
		double sinA)
{
	double	k;

	if (data->p.dy)
	{
		k = step * (double)data->p.dy;
		try_move(data, k * cosA, k * sinA);
	}
	if (data->p.dh)
	{
		k = step * (double)data->p.dh;
		try_move(data, k * (-sinA), k * (cosA));
	}
}

// printf("offset: %.30f\n", data->p.jump.offset);
// --- view: keys + mouse ------------------------
void	handle_view(t_data *data, double dt)
{
	double	yaw_delta;
	double	pitch_delta;

	yaw_delta = 0.0;
	pitch_delta = 0.0;
	if (data->p.dx)
		yaw_delta += data->p.rs * dt * (double)data->p.dx;
	if (data->p.dv)
		pitch_delta += MOV_PITCH_SPEED * dt * (double)data->p.dv;
	if (data->mouse.lock)
	{
		yaw_delta += data->mouse.dx_accum * 0.003;
		pitch_delta += -(data->mouse.dy_accum * 2.0);
		data->mouse.dx_accum = 0;
		data->mouse.dy_accum = 0;
	}
	data->p.angle = normalize_angle(data->p.angle + yaw_delta);
	data->p.pitch = clampd(data->p.pitch + pitch_delta, 0.0,
			(double)WIN_HEIGHT);
}
