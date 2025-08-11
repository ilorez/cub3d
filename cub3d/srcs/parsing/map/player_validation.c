#include "../includes/container.h"

int	validate_player_pos(t_map *map, t_cub_data *cub_data)	
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < get_effective_line_width(map->arr[i]))
		{
			if (is_player_char(map->arr[i][j]))
			{
				if (!player_count)
				{
					cub_data->player.pos.x = i;
					cub_data->player.pos.y = j;
					cub_data->player.dir = map->arr[i][j];
				}
				player_count++;
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

// checking if the player can  walk in the map 
int	validate_player_can_move(t_map *map, t_cub_data *cub_data)
{
	int	x;
	int	y;

	x = cub_data->player.pos.x;
	y = cub_data->player.pos.y;
	if (x > 0 && is_walkable(map->arr[x - 1][y])) // top
		return (1);
	if (x + 1 < map->rows && is_walkable(map->arr[x + 1][y])) // bottom
		return (1);
	if (y > 0 && is_walkable(map->arr[x][y - 1])) // left
		return (1);
	if (y + 1 < (int)ft_strlen(map->arr[x]) && is_walkable(map->arr[x][y + 1])) // right
		return (1);
	return (0); // trapped on all sides
}
