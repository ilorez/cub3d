/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:41:34 by ablabib           #+#    #+#             */
/*   Updated: 2025/09/02 10:57:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/container.h"

static void	set_player_angle(t_cub_data *cub_data, char dir)
{
	if (dir == 'E')
		cub_data->angle = 0;
	else if (dir == 'S')
		cub_data->angle = PI / 2;
	else if (dir == 'W')
		cub_data->angle = PI;
	else if (dir == 'N')
		cub_data->angle = 3 * PI / 2;
}

static void	init_player(t_cub_data *cub_data, int i, int j, char dir)
{
	cub_data->pos.x = i;
	cub_data->pos.y = j;
	set_player_angle(cub_data, dir);
}

int	validate_player_pos(t_map *map, t_cub_data *cub_data)
{
	int	i;
	int	j;
	int	player_count;
	int	effective_line;

	player_count = 0;
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		effective_line = get_effective_line_width(map->arr[i]);
		while (j < effective_line)
		{
			if (is_player_char(map->arr[i][j]))
			{
				if (!player_count)
					init_player(cub_data, i, j, map->arr[i][j]);
				player_count++;
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

int	validate_player_can_move(t_map *map, t_cub_data *cub_data)
{
	int	x;
	int	y;

	if (!map || !map->arr)
		return (0);
	x = cub_data->pos.x;
	y = cub_data->pos.y;
	if (x < 0 || x >= map->rows || y < 0 || y >= (int)ft_strlen(map->arr[x]))
		return (0);
	if (x > 0 && map->arr[x - 1] && is_walkable(map->arr[x - 1][y]))
		return (1);
	if (x + 1 < map->rows && map->arr[x + 1] && is_walkable(map->arr[x + 1][y]))
		return (1);
	if (y > 0 && is_walkable(map->arr[x][y - 1]))
		return (1);
	if (y + 1 < (int)ft_strlen(map->arr[x]) && is_walkable(map->arr[x][y + 1]))
		return (1);
	return (0);
}

// checking if the player can  walk in the map
// int	validate_player_can_move(t_map *map, t_cub_data *cub_data)
// {
// 	int	x;
// 	int	y;

// 	x = cub_data->p_x;
// 	y = cub_data->p_y;
// 	if (y > 0 && is_walkable(map->arr[x - 1][y]))
// 		return (1);
// 	if (y + 1 < map->rows && is_walkable(map->arr[x + 1][y]))
// 		return (1);
// 	if (x > 0 && is_walkable(map->arr[x][y - 1]))
// 		return (1);
// 	if (x + 1 < (int)ft_strlen(map->arr[x]) && is_walkable(map->arr[x][y + 1]))
// 		return (1);
// 	return (0); // trapped on all sides
// }

// int	validate_player_pos(t_map *map, t_cub_data *cub_data)
// {
// 	int	i;
// 	int	j;
// 	int	player_count;

// 	i = 0;
// 	player_count = 0;
// 	while (i < map->rows)
// 	{
// 		j = 0;
// 		while (j < get_effective_line_width(map->arr[i]))
// 		{
// 			if (is_player_char(map->arr[i][j]))
// 			{
// 				if (!player_count)
// 				{
// 					cub_data->player.pos.y = i;
// 					cub_data->player.pos.x = j;
// 					if (map->arr[i][j] == 'E')
// 						cub_data->player.angle = 0;
// 					else if (map->arr[i][j] == 'S')
// 						cub_data->player.angle = PI / 2;
// 					else if (map->arr[i][j] == 'W')
// 						cub_data->player.angle = PI;
// 					else if (map->arr[i][j] == 'N')
// 						cub_data->player.angle = 3 * PI / 2;
// 				}
// 				player_count++;
// 			}
// 			j++; }
// 		i++;
// 	}
// 	return (player_count == 1);
// }
