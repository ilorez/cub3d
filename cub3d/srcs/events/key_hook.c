/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 10:30:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/03 10:16:28 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/events.h"

// update rotaion speed
static void	ft_update_settings(int keycode, t_data *data)
{
	if (keycode == KEY_RSUP)
	{
		data->p.rs += ROTATION_SPEED_INC;
		if (data->p.rs > ROTATION_SPEED_MAX)
			data->p.rs = ROTATION_SPEED_MAX;
	}
	else if (keycode == KEY_RSDOWN)
	{
		data->p.rs -= ROTATION_SPEED_INC;
		if (data->p.rs < ROTATION_SPEED_MIN)
			data->p.rs = ROTATION_SPEED_MIN;
	}
	else if (keycode == KEY_SPUP)
	{
		data->p.speed += data->p.sp_inc;
		if (data->p.speed > data->p.sp_max)
			data->p.speed = data->p.sp_max;
	}
	else if (keycode == KEY_SPDOWN)
	{
		data->p.speed -= data->p.sp_inc;
		if (data->p.speed < data->p.sp_min)
			data->p.speed = data->p.sp_min;
	}
}

static void	on_click_esc(t_data *data)
{
	if (data->mouse.lock)
		unlock_mouse(data);
	else
		data->is_running = 0;
}

static void	on_jump(t_data *data)
{
	data->p.jump.is = 1;
	data->p.jump.velocity = JUMP_SPEED;
}

int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		on_click_esc(data);
	if (keycode == KEY_MUP)
		data->p.dy = 1;
	else if (keycode == KEY_MDOWN)
		data->p.dy = -1;
	else if (keycode == KEY_MRIGHT)
		data->p.dh = 1;
	else if (keycode == KEY_MLEFT)
		data->p.dh = -1;
	else if (keycode == KEY_UP)
		data->p.dv = 1;
	else if (keycode == KEY_DOWN)
		data->p.dv = -1;
	else if (keycode == KEY_LEFT)
		data->p.dx = -1;
	else if (keycode == KEY_RIGHT)
		data->p.dx = 1;
	else if (keycode == KEY_SPACE && !data->p.jump.is)
		on_jump(data);
	if (keycode == KEY_OPEN_DOOR)
		toggle_door(data);
	else
		ft_update_settings(keycode, data);
	return (EXIT_SUCCESS);
}

// printf("release up :%d\n", keycode);
int	ft_key_release(int keycode, t_data *data)
{
	if (keycode == KEY_MUP || keycode == KEY_MDOWN)
		data->p.dy = 0;
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		data->p.dx = 0;
	else if (keycode == KEY_MLEFT || keycode == KEY_MRIGHT)
		data->p.dh = 0;
	else if (keycode == KEY_UP || keycode == KEY_DOWN)
		data->p.dv = 0;
	return (EXIT_SUCCESS);
}
