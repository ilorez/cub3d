/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:06:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/03 11:39:14 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/events.h"

// render window components
static void		draw(t_data *data);
static time_t	calculate_delta_time(t_data *data);

int	ft_loop_hook(t_data *data)
{
	time_t	current_t;

	if (!data)
		return (1);
	current_t = calculate_delta_time(data);
	draw(data);
	if (!data->is_running)
		ft_handle_window_exit(data, EXIT_SUCCESS);
	return (0);
}

static void	draw(t_data *data)
{
	render_map(data);
	handel_jump(data);
	data->p.pitch += data->p.jump.offset / 2;
	render_fc(data);
	raycast(data);
	render_player(data);
	render_player_skin(data);
	render_aim(data->img, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	data->p.pitch -= data->p.jump.offset / 2;
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
