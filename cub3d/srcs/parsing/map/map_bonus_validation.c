#include "../../../includes/container.h"

int is_bonus_walkable(char c)
{
    return (c == '0' || c == 'D' || is_player_char(c));
}
// bonus part map validation 
int is_valid_map_char_bonus(char c)
{
    return (c == '0' || c == '1' || c == 'N' || c == 'S' || 
            c == 'E' || c == 'W' || c == ' ' || c == 'D');
}

int	print_map_error(char *msg, int row, int col)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(" at row ", 2);
	ft_putnbr_fd(row, 2);
	ft_putstr_fd(" col ", 2);
	ft_putnbr_fd(col, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int	validate_walkable_surroundings_bonus(t_map *map, int row, int col)
{
	char	adj;

	if (!is_within_bounds(map, row - 1, col)
		|| !is_within_bounds(map, row + 1, col)
		|| !is_within_bounds(map, row, col - 1)
		|| !is_within_bounds(map, row, col + 1))
		return (print_map_error("Walkable out of bounds", row, col));
	adj = map->arr[row - 1][col];
	if (adj == ' ' || (!is_bonus_walkable(adj) && adj != '1'))
		return (print_map_error("Invalid walkable neighbor (top)", row, col));
	adj = map->arr[row + 1][col];
	if (adj == ' ' || (!is_bonus_walkable(adj) && adj != '1'))
		return (print_map_error("Invalid walkable neighbor (bottom)", row, col));
	adj = map->arr[row][col - 1];
	if (adj == ' ' || (!is_bonus_walkable(adj) && adj != '1'))
		return (print_map_error("Invalid walkable neighbor (left)", row, col));
	adj = map->arr[row][col + 1];
	if (adj == ' ' || (!is_bonus_walkable(adj) && adj != '1'))
		return (print_map_error("Invalid walkable neighbor (right)", row, col));
	return (1);
}

static int	validate_door(t_map *map, int row, int col)
{
	char	t;
	char	b;
	char	l;
	char	r;

	if (!is_within_bounds(map, row - 1, col)
		|| !is_within_bounds(map, row + 1, col)
		|| !is_within_bounds(map, row, col - 1)
		|| !is_within_bounds(map, row, col + 1))
		return (print_map_error("Door out of bounds", row, col), 0);
	t = map->arr[row - 1][col];
	b = map->arr[row + 1][col];
	l = map->arr[row][col - 1];
	r = map->arr[row][col + 1];
	if (t == 'D' || b == 'D' || l == 'D' || r == 'D')
		return (print_map_error("Door adjacent to another door", row, col), 0);
	if ((t == '1' || t == 'D') && (b == '1' || b == 'D')
		&& (l == '1' || l == 'D') && (r == '1' || r == 'D'))
		return (print_map_error("Door completely boxed by walls/doors", row, col), 0);
	if ((t == '1' && b == '1') || (l == '1' && r == '1'))
		return (1);
	// If none of the above, it is invalid
	return (print_map_error(
		"Door must have at least 2 walls vertically or horizontally", row, col), 0);
}



int	validate_map_closure_bonus(t_map *map)
{
	int	i;
	int	j;
	int	cols;
	int door;

	i = 0;
	door = 0;
	while (i < map->rows)
	{
		j = 0;
		cols = get_effective_line_width(map->arr[i]);
		while (j < cols)
		{
			if (is_bonus_walkable(map->arr[i][j]))
			{
                if (map->arr[i][j] == 'D')
                {
					door++;
                    if (!validate_door(map,i,j))
                        return 0;
                }
				if (!validate_walkable_surroundings_bonus(map, i, j))
					return (0);
			}
			j++;
		}
		i++;
	}
	if (!door)
		return (printf("DOORs count [%d]\n",door),0);
	else
		return (1);
}

static int validate_characters_bonus(t_map *map)
{
	int i;
	int j;
	int col;

	i = 0;
	while(i < map->rows)
	{
		j = 0;
		col  = get_effective_line_width(map->arr[i]);
		while (j < col)
		{	
			if (!is_valid_map_char_bonus(map->arr[i][j]))
				return 0;
			j++; 
		}
		i++; 
	}
	return 1;
}

int	validate_map_bonus(t_cub_data *data)
{
	t_map	*map;
    
	map = &data->map;
	if (!map->arr)
		return (print_map_error("Map array is NULL", -1, -1),0);
	if (!validate_characters_bonus(map))
		return (print_map_error("Invalid character in map", -1, -1),0);
	if (!validate_player_pos(map, data))
		return (print_map_error("Invalid or missing player", -1, -1),0);
	if (!validate_player_can_move(map, data))
		return (print_map_error("Player cannot move", -1, -1),0);
	if (!validate_map_closure_bonus(map))
		return (0);
	return (1);
}
