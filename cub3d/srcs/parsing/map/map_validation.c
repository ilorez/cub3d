#include "../includes/container.h"
#include <stdbool.h>

int	is_map_start(char *line)
{
    int i;

    i = 0;
    while(line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
        i++;
    return (line[i] == '1' || line[i] == '0');
}

int is_valid_map_char(char c)
{
    return (c == '0' || c == '1' || c == 'N' || c == 'S' || 
            c == 'E' || c == 'W' || c == ' ');
}

int is_player_char(char c)
{
    return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int is_walkable(char c)
{
    return (c == '0' || is_player_char(c));
}

int is_within_bounds(t_map *map, int row, int col)
{
    if (row < 0 || row >= map->rows)
        return 0;
    return (col >= 0 && col < (int)ft_strlen(map->arr[row]));
}

// 1) check top && buttom 
// 2) check empty spaces 
// 3) check player poss if its out of band 
// 4) with in bound , this is good for checking if space is inside of the map or outside 


/*
	1) Check that the map contains only valid characters
	2) Check that the map has exactly one player start position (N, S, E, or W)
	3) Check that the map is fully enclosed (closed by walls)
	4) Check that no walkable area or player start is out-of-bounds
	5) Check that the player can actually move
	6) Optionally, check for empty lines or gaps inside the map
	7) Calculate and store map dimensions (width, height, rows, columns)
*/

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
// checking if the player can  walk in the map 
int	validate_player_can_move(t_map *map,t_cub_data *cub_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < (int)ft_strlen(map->arr[i]))
		{
			if (is_player_char(map->arr[i][j]))
			{
				cub_data->player.pos.x = i;
				cub_data->player.pos.y = j;
				if (i > 0 && is_walkable(map->arr[i - 1][j]))       // top
					return (1);
				if (i + 1 < map->rows && is_walkable(map->arr[i + 1][j])) // bottom
					return (1);
				if (j > 0 && is_walkable(map->arr[i][j - 1]))       // left
					return (1);
				if (j + 1 < (int)ft_strlen(map->arr[i]) && is_walkable(map->arr[i][j + 1])) // right
					return (1);
				return (0); // trapped on all sides
			}
			j++;
		}
		i++;
	}
	return (0);
}


int	validate_map(t_cub_data *data)
{
	t_map	*map;

	map = &data->map;
	if (!map->arr)
		return (0);
	// if (!validate_characters(map))
	// 	return (0);
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
