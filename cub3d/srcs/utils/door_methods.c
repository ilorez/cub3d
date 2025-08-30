/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:24:48 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 11:34:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

t_intcor	translate_to_map_cor(t_cor *pos)
{
	t_intcor	cor;

	cor.x = (int)floor(pos->x / (double)BLOCK_SIZE);
	cor.y = (int)floor(pos->y / (double)BLOCK_SIZE);
	return (cor);
}

int	is_door(t_cor pos, t_data *data)
{
	int	i;
	int	j;

	i = (int)floor(pos.x / (double)BLOCK_SIZE);
	j = (int)floor(pos.y / (double)BLOCK_SIZE);
	if (i < 0 || j < 0 || j >= data->map->rows || i >= data->map->columns)
		return (0);
	if ((data->map->grid)[j][i] == 3 || (data->map->grid)[j][i] == -3)
		return (3);
	return (0);
}

/*
	^
	|
<------> look hor
	|
	v
  look ver
*/
void	toggle_door(t_data *data)
{
	t_player	p;
	t_cor		new_pos;
	t_intcor	cor;

	p = data->p;
	if (is_door(p.pos, data))
		return ;
	new_pos.x = p.pos.x + ((BLOCK_SIZE * 0.75) * cos(p.angle));
	new_pos.y = p.pos.y + ((BLOCK_SIZE * 0.75) * sin(p.angle));
	if (!is_door(new_pos, data))
		return ;
	cor = translate_to_map_cor(&new_pos);
	data->map->grid[cor.y][cor.x] *= -1;
}
