#include "../includes/container.h"

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