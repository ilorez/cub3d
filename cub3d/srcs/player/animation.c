/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 10:34:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/29 16:05:40 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

void	pl_animation_update(t_pl_animation *pa)
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
			pa->is_animating = 0;
		}
		pa->last_frame = now;
	}
}

void	render_player_skin(t_data *d)
{
	t_put_params	p;

	pl_animation_update(&d->pa);
	p.h = 900;
	p.w = 900;
	p.x = WIN_WIDTH / 2 - p.w / 2 + d->p.dh * 20;
	p.y = WIN_HEIGHT / 2.0 + d->p.pitch - 200 - 1 - d->p.jump.offset;
	if (d->pa.texs[d->pa.frame_order[d->pa.i]].loaded)
		ft_mlx_put_image(&d->img, &(d->pa.texs[d->pa.frame_order[d->pa.i]].img),
			p);
}

void	handel_jump(t_data *data)
{
	if (!data->p.jump.is)
		return ;
	data->p.jump.offset += data->p.jump.velocity;
	data->p.jump.velocity -= GRAVITY;
	if (data->p.jump.offset <= 0.0)
	{
		data->p.jump.offset = 0.0;
		data->p.jump.velocity = 0.0;
		data->p.jump.is = 0;
	}
}
