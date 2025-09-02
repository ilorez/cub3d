/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:32:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 15:32:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/floor_and_ceiling.h"
#include <math.h>

void	render_fc(t_data *data)
{
	t_rect	floor;
	t_rect	ceiling;

	ceiling.color = merge_t_color(data->map_info->ceiling_color);
	ceiling.width = WIN_WIDTH;
	ceiling.height = data->p.pitch;
	ceiling.pos.x = 0;
	ceiling.pos.y = 0;
	floor.color = merge_t_color(data->map_info->floor_color);
	floor.width = WIN_WIDTH;
	floor.height = WIN_HEIGHT - data->p.pitch;
	floor.pos.x = 0;
	floor.pos.y = ceiling.height;
	render_rect(data->img, ceiling);
	render_rect(data->img, floor);
}
