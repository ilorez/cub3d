#include "../includes/container.h"

int	validate_walkable_surroundings(t_map *map, int row, int col)
{
	char	adjacent_cell;

	if (!is_within_bounds(map, row - 1, col))
		return (0);
	adjacent_cell = map->arr[row - 1][col];// top 
	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell) && adjacent_cell != '1'))
		return (0);
	if (!is_within_bounds(map, row + 1, col))
		return (0);
	adjacent_cell = map->arr[row + 1][col]; // bottom
	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell) && adjacent_cell != '1'))
		return (0);
	if (!is_within_bounds(map, row, col - 1))
		return (0);
	adjacent_cell = map->arr[row][col - 1];// left
	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell) && adjacent_cell != '1'))
		return (0);
	if (!is_within_bounds(map, row, col + 1))
		return (0);
	adjacent_cell = map->arr[row][col + 1];// right
	if (adjacent_cell == ' ' || (!is_walkable(adjacent_cell) && adjacent_cell != '1'))
		return (0);
	return (1);
}

int	validate_map_closure(t_map *map)
{
	int	i;
	int	j;
    int columns;

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



// 1) check top && buttom  
// 2) check empty spaces 
// 3) check player poss if its out of band 
// 4) with in bound , this is good for checking if space is inside of the map or outside 


/*
	1) Check that the map contains only valid characters [x]
	2) Check that the map has exactly one player start position (N, S, E, or W) [-]
	3) Check that the map is fully enclosed (closed by walls)  [-]
	4) Check that no walkable area or player start is out-of-bounds [x]
	5) Check that the player can actually move [-]
	6) Optionally, check for empty lines or gaps inside the map [x]
	7) Calculate and store map dimensions (width, height, rows, columns) [-]
*/

int	validate_map(t_cub_data *data)
{
	t_map	*map;

	map = &data->map;
	if (!map->arr)
		return (0);
	// if (!validate_characters(map))
	// 	return (0);
	/* validate that there is only one player here */
	// if (!validate_player(map))
	// 	return (0);
	// if (!validate_map_has_walkable_area(map))
	// 	return (0);
	if (!validate_player_can_move(map,data))
		return 0;
	if (!validate_map_closure(map))
		return (0);
	return (1);
}
