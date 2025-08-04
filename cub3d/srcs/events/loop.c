/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:06:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/04 15:50:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/events.h"
#include <mlx.h>

int	ft_loop_hook(t_data *data)
{
	if (!data)
		  return (1);
	// draw functions;
  render_map(data->map);
  render_player(data);
  //printf("px:%f, py:%f", data->p.pos.x, data->p.pos.y);
  mlx_put_image_to_window(data->mlx, data->win, data->map->data.img, 0, 0);
	return (0);
}


