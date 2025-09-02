/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:37:06 by ablabib           #+#    #+#             */
/*   Updated: 2025/09/02 10:56:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/container.h"

static int	check_adjacent_cell(t_map *map, int row, int col)
{
	char	cell;

	if (!is_within_bounds(map, row, col))
		return (0);
	cell = map->arr[row][col];
	if (cell == ' ' || (!is_walkable(cell) && cell != '1'))
		return (0);
	return (1);
}

int	validate_walkable_surroundings(t_map *map, int row, int col)
{
	if (!check_adjacent_cell(map, row - 1, col))
		return (0);
	if (!check_adjacent_cell(map, row + 1, col))
		return (0);
	if (!check_adjacent_cell(map, row, col - 1))
		return (0);
	if (!check_adjacent_cell(map, row, col + 1))
		return (0);
	return (1);
}

int	validate_map_closure(t_map *map)
{
	int	i;
	int	j;
	int	columns;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		columns = get_effective_line_width(map->arr[i]);
		while (j < columns)
		{
			if (is_walkable(map->arr[i][j]))
			{
				if (!validate_walkable_surroundings(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_characters(t_map *map)
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
			if (!is_valid_map_char(map->arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate_map(t_cub_data *data)
{
	t_map	*map;

	map = &data->map;
	if (!map->arr)
		return (0);
	if (!validate_characters(map))
		return (0);
	if (!validate_player_pos(map, data))
		return (0);
	if (!validate_player_can_move(map, data))
		return (0);
	if (!validate_map_closure(map))
		return (0);
	return (1);
}

// int	validate_walkable_surroundings(t_map *map, int row, int col)
// {
// 	char	adjacent_cell;

// 	if (!is_within_bounds(map, row - 1, col))
// 		return (0);
// 	adjacent_cell = map->arr[row - 1][col];
// 	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell)
// 			&& adjacent_cell != '1'))
// 		return (0);
// 	if (!is_within_bounds(map, row + 1, col))
// 		return (0);
// 	adjacent_cell = map->arr[row + 1][col];
// 	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell)
// 			&& adjacent_cell != '1'))
// 		return (0);
// 	if (!is_within_bounds(map, row, col - 1))
// 		return (0);
// 	adjacent_cell = map->arr[row][col - 1];
// 	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell)
// 			&& adjacent_cell != '1'))
// 		return (0);
// 	if (!is_within_bounds(map, row, col + 1))
// 		return (0);
// 	adjacent_cell = map->arr[row][col + 1];
// 	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell)
// 			&& adjacent_cell != '1'))
// 		return (0);
// 	return (1);
// }
