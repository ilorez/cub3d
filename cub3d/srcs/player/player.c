/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:11:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/16 13:41:11 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

void	update_player_pos(t_data *data)
{
	double	dt;
	double	step;
	double	cos_a;
	double	sin_a;

	cos_a = cos(data->p.angle);
	sin_a = sin(data->p.angle);
	dt = data->delta_time;
	step = data->p.speed * dt;
	handle_keyboard_move(data, step, cos_a, sin_a);
	handle_view(data, dt);
}

void	render_player(t_data *data)
{
	t_cercl	cercl;
	t_line	line;

	update_player_pos(data);
	cercl.center = (t_cor){MAP_SIZE / 2.0, MAP_SIZE / 2.0};
	cercl.radius = data->p.size;
	cercl.color = PLAYER_COLOR;
	render_filled_cercle(data->map->data, cercl);
	line.color = COLOR_RED;
	line.s = cercl.center;
	line.e.x = line.s.x + cos(data->p.angle) * BLOCK_SIZE / 2;
	line.e.y = line.s.y + sin(data->p.angle) * BLOCK_SIZE / 2;
	render_line(data->map->data, &line);
}
// printf("endx: %f\n endy: %f\n", line.e.x, line.e.y);
// printf("Player : x: %f, y: %f\n",
// data->p.pos.x, data->p.pos.y);
