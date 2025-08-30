#include "../../includes/container.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->arr)
	{
		free_split(map->arr);
		map->arr = NULL;
	}
	map->rows = 0;
	map->columns = 0;
}

void  free_converted_map(t_map *map)
{
	int i;

	if (!map)
		return ;
	i = 0;
	while(map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	free_cub_data(t_cub_data *data)
{
	if (!data)
		return ;
	if (data->no_path)
		free(data->no_path);
	if (data->so_path)
		free(data->so_path);
	if (data->we_path)
		free(data->we_path);
	if (data->ea_path)
		free(data->ea_path);
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	free_map(&data->map);
	if (data->map.grid)
		free_converted_map(&data->map);
	data->map_found = 0;
}

// free **char str
void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}