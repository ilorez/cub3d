/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:06:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/28 12:21:31 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/events.h"
#include <mlx.h>
#include <stdlib.h>

time_t			ft_time_now(void);
// render window components
static void		draw(t_data *data);
static time_t	calculate_delta_time(t_data *data);
static void		count_fbs(t_data *data, time_t current_t);

int	ft_loop_hook(t_data *data)
{
	time_t	current_t;

	if (!data)
		return (1);
	current_t = calculate_delta_time(data);
	draw(data);
	count_fbs(data, current_t);
	if (!data->is_running)
		ft_handle_window_exit(data, EXIT_SUCCESS);
	return (0);
}


static void	pl_animation_update(t_pl_animation *pa)
{
	time_t	now;
	time_t	frame_time;

	if (!pa->is_animating)
		return ;
	now = ft_time_now();
	frame_time = pa->duration / pa->frame_count;
	if (now - pa->last_frame >= frame_time)
	{
		pa->i++;
		if (pa->i >= pa->frame_count)
		{
			pa->i = 0;
			pa->is_animating = 0; /* stop after one cycle */
		}
		pa->last_frame = now;
	}
}


static void	render_player_skin(t_data *d)
{
	t_put_params	p;

	pl_animation_update(&d->pa);
	p.h = 900;
	p.w = 900;
	p.x = WIN_WIDTH / 2 - p.w / 2 + d->p.dh * 20;
	p.y = WIN_HEIGHT / 2.0 + d->p.pitch - 200 - 1 - d->p.jump.offset;
	if (d->pa.texs[d->pa.frame_order[d->pa.i]].loaded)
		ft_mlx_put_image(&d->img,
			&(d->pa.texs[d->pa.frame_order[d->pa.i]].img), p);
}

static void	draw(t_data *data)
{
	render_map(data);
  handel_jump(data);
  data->p.pitch += data->p.jump.offset/2;
	render_fc(data);
	raycast(data);
	render_player(data);
  render_player_skin(data);
	render_aim(data->img, WIN_WIDTH / 2, WIN_HEIGHT / 2);
  data->p.pitch -= data->p.jump.offset/2;
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->map->data.img, 0, 0);
}

static time_t	calculate_delta_time(t_data *data)
{
	time_t	current_t;

	current_t = ft_time_now();
	if (data->lastf == 0)
		data->lastf = current_t;
	data->delta_time = (current_t - data->lastf) / 1000.0f;
	data->lastf = current_t;
	return (current_t);
}

static void	count_fbs(t_data *data, time_t current_t)
{
	data->frame_count++;
	if (current_t - data->last_fps_time >= 1000.0)
	{
		printf("FPS: %d\n", data->frame_count);
		data->frame_count = 0;
		data->last_fps_time = current_t;
	}
}

