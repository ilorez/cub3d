#include "../../includes/container.h"

static void	free_int_grid(int **grid, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static int	char_to_int(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2); // player start
	if (c == ' ')
		return (3); // space/outside
	return (-1); // invalid char
}

int	convert_char_arr_to_int_grid(t_map *map)
{
	int	i;
	int	j;

	map->grid = malloc(sizeof(int *) * map->rows);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = malloc(sizeof(int) * (get_effective_line_width(map->arr[i])));
		if (!map->grid[i])
		{
			free_int_grid(map->grid, i);
			map->grid = NULL;
			return (0);
		}
		j = 0;
		while (j < get_effective_line_width(map->arr[i]))
		{
			map->grid[i][j] = char_to_int(map->arr[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}
