/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:06:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 18:12:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/events.h"
#include <mlx.h>
#include <stdio.h>

int	ft_loop_hook(t_data *data)
{
  //t_rect rect;

	if (!data)
		  return (1);
  //rect.color = COLOR_RED;
  //rect.pos.x = 0;
  //rect.pos.y = 0;
  //rect.width = 100;
  //rect.height = 100;
	// draw functions;
  render_map(data->map);
  mlx_put_image_to_window(data->mlx, data->win, data->map->data.img, 0, 0);
	return (0);
}


