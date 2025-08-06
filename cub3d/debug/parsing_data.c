#include "../includes/container.h"

void	print_color(const char *label, t_color color)
{
	printf("%s: R: %d, G: %d, B: %d\n", label, color.r, color.g, color.b);
}

void	print_player(t_player *p)
{
	printf("Player:\n");
	printf("  Position: (%.2f, %.2f)\n", p->pos.x, p->pos.y);
	printf("  Direction: %c\n", p->dir);
	printf("  Vector (dx, dy): (%.2f, %.2f)\n", p->dx, p->dy);
	printf("  Angle: %.2f\n", p->angle);
	printf("  Size: %d, Speed: %d, Rotation Speed: %.2f\n",
		p->size, p->speed, p->rs);
}

void	print_map(char **grid, int height)
{
	int	i;

	printf("Map:\n");
	i = 0;
	while (i < height)
	{
		printf("  %s\n", grid[i]);
		i++;
	}
}

void	print_cub_data(t_cub_data *data)
{
	if (!data)
	{
		printf("No data to print.\n");
		return ;
	}
	printf("Texture Paths:\n");
	printf("  NO: %s\n", data->no_path);
	printf("  SO: %s\n", data->so_path);
	printf("  WE: %s\n", data->we_path);
	printf("  EA: %s\n", data->ea_path);
	print_color("Floor Color", data->floor_color);
	print_color("Ceiling Color", data->ceiling_color);
	// print_player(&data->map.player);
	// print_map(data->map.grid, data->map.height);
}
