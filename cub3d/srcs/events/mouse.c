/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:47:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/29 10:30:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/events.h"

int	ft_mouse_click(int key, int x, int y, t_data *data)
{
	(void)x, (void)y, (void)data;
	if (key == KEY_MOUSE_LEFT)
		toggle_door(data);
	else if (key == KEY_MOUSE_RIGHT)
	{
		if (!data->pa.is_animating)
		{
			data->pa.is_animating = 1;
			data->pa.i = 0;
			data->pa.last_frame = ft_time_now();
		}
	}
	return (0);
}

int	on_mouse_enter(t_data *data)
{
	if (!(data->mouse.lock))
		lock_mouse(data);
	return (0);
}

static int	limit_d(int d, int min, int max, int deadzone)
{
	if (d < min)
		d = min;
	if (d > max)
		d = max;
	if (d <= deadzone && d >= -1 * deadzone)
		d = 0;
	return (d);
}

int	on_mouse_move(int x, int y, t_data *d)
{
	int	dx;
	int	dy;

	if (!d->mouse.lock)
		return (0);
	if (d->mouse.ignore_next_move)
	{
		d->mouse.ignore_next_move = 0;
		return (0);
	}
	dx = x - WIN_WIDTH / 2;
	dy = y - WIN_HEIGHT / 2;
	dx = limit_d(dx, -WIN_WIDTH / 2, WIN_WIDTH / 2, 1);
	dy = limit_d(dy, -WIN_HEIGHT / 2, WIN_HEIGHT / 2, 1);
	d->mouse.dx_accum += dx;
	d->mouse.dy_accum += dy;
	mlx_mouse_move(d->mlx, d->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	d->mouse.ignore_next_move = 1;
	return (0);
}
