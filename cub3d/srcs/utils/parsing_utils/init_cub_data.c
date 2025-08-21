#include "../includes/container.h"

void	init_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_player(t_player *player)
{
	player->pos.x = -1;
	player->pos.y = -1;
	player->angle = -1;
}

// void	init_map(t_map *map)
// {
// 	map->grid = NULL;
// 	map->height = 0;
// 	map->width = 0;
// 	init_player(&map->player);
// }

void	init_cub_data(t_cub_data *data)
{
	data->no_path = NULL;
	data->so_path = NULL;
	data->we_path = NULL;
	data->ea_path = NULL;
	init_color(&data->floor_color);
	init_color(&data->ceiling_color);
	// init_map(&data->map);
	data->map_found = 0;
}
