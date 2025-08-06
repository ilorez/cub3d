/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:06:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/06 12:58:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/events.h"

time_t	ft_time_now(void);

int	ft_loop_hook(t_data *data)
{
  time_t current_t;

  if (!data)
		  return (1);
  current_t = ft_time_now();
  if (data->lastf == 0)
    data->lastf = current_t;
  data->delta_time = (current_t -  data->lastf) / 1000.0f;
  data->lastf = current_t;
	
  // draw functions;
  render_map(data->map);
  raycast(data);
  render_player(data);
  //mlx_string_put(data->mlx, data->win, WIN_WIDTH - 100, 20, 0xFFFFFF, "FPS:");
  mlx_put_image_to_window(data->mlx, data->win, data->map->data.img, 0, 0);

  // count fbs
  data->frame_count++;
	if (current_t - data->last_fps_time >= 1000.0) // every 1 second
	{
		printf("FPS: %d\n", data->frame_count);
		data->frame_count = 0;
		data->last_fps_time = current_t;
	}
	return (0);
}


time_t	ft_time_now(void)
{
	time_t			mills;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	mills = (time_t)tv.tv_sec * 1000 + (time_t)tv.tv_usec / 1000;
	return (mills);
}
