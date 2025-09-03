/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:31:54 by ablabib           #+#    #+#             */
/*   Updated: 2025/09/03 11:56:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/container.h"

static int	check_door(t_map *map, int i, int j, int *door)
{
	if (map->arr[i][j] == 'D')
	{
		(*door)++;
		if (!validate_door(map, i, j))
			return (0);
	}
	return (1);
}

static int	check_tile(t_map *map, int i, int j, int *door)
{
	if (is_bonus_walkable(map->arr[i][j]))
	{
		if (!check_door(map, i, j, door))
			return (0);
		if (!validate_walkable_surroundings_bonus(map, i, j))
			return (0);
	}
	return (1);
}

int	validate_map_closure_bonus(t_map *map)
{
	int	i;
	int	j;
	int	cols;
	int	door;

	i = 0;
	door = 0;
	while (i < map->rows)
	{
		j = 0;
		cols = get_effective_line_width(map->arr[i]);
		while (j < cols)
		{
			if (!check_tile(map, i, j, &door))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	validate_characters_bonus(t_map *map)
{
	int	i;
	int	j;
	int	col;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		col = get_effective_line_width(map->arr[i]);
		while (j < col)
		{
			if (!is_valid_map_char_bonus(map->arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map_bonus(t_cub_data *data)
{
	t_map	*map;

	map = &data->map;
	if (!map->arr)
		return (print_map_error("Map array is NULL", -1, -1), 0);
	if (!validate_characters_bonus(map))
		return (print_map_error("Invalid character in map\n", -1, -1), 0);
	if (!validate_player_pos(map, data))
		return (print_map_error("Invalid or missing player\n", -1, -1), 0);
	if (!validate_player_can_move(map, data))
		return (print_map_error("Player cannot move\n", -1, -1), 0);
	if (!validate_map_closure_bonus(map))
		return (0);
	return (1);
}

// int	validate_map_closure_bonus(t_map *map)
// {
// 	int	i;
// 	int	j;
// 	int	cols;
// 	int door;

// 	i = 0;
// 	door = 0;
// 	while (i < map->rows)
// 	{
// 		j = 0;
// 		cols = get_effective_line_width(map->arr[i]);
// 		while (j < cols)
// 		{
// 			if (is_bonus_walkable(map->arr[i][j]))
// 			{
//                 if (map->arr[i][j] == 'D')
//                 {
// 					door++;
//                     if (!validate_door(map,i,j))
//                         return (0);
//                 }
// 				if (!validate_walkable_surroundings_bonus(map, i, j))
// 					return (0);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	if (!door)
// 		return (print_map_error("MAP SHOULD AT LEAST HAVE 1 DOOR\n",-1,-1),0);
// 	else
// 		return (1);
// }
