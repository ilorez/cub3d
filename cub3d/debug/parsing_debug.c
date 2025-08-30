#include "../includes/container.h"

void	print_color(const char *label, t_color color)
{
	printf("%s:\n",label);
	printf("\033[38;2;255;0;0mRED   \033[0m: %d\n", color.r);   // Red
	printf("\033[38;2;0;255;0mGREEN \033[0m: %d\n", color.g);   // Green
	printf("\033[38;2;0;0;255mBLUE  \033[0m: %d\n", color.b);   // Blue
}

// Function to print the integer grid (for debugging)
void print_int_map(t_cub_data *data)
{
    int i, j;

    printf("=== Integer Map Grid ===\n");
    if (!data || !data->map.grid)
    {
        printf("Map grid is NULL or not initialized.\n");
        return;
    }

    for (i = 0; i < data->map.rows; i++)
    {
		j = 0;
        while (j < get_effective_line_width(data->map.arr[i]))
        {
            printf("%d", data->map.grid[i][j]);
			j++;
        }
        printf("\n");
    }
    // printf("Grid dimensions: %d rows x %d columns\n", data->map.rows, data->map.columns);
}

void	print_player(t_cub_data *p)
{
	printf("---------Player:----------\n");
	printf("  Position: (x = %d, y = %d)\n", p->p_x, p->p_y);
	printf("  Direction: %f\n", p->p_angle);
	// printf("  Vector (dx, dy): (%.2f, %.2f)\n", p->dx, p->dy);
	// printf("  Angle: %.2f\n", p->angle);
	// printf("  Size: %d, Speed: %d, Rotation Speed: %.2f\n",
	// 	p->size, p->speed, p->rs);
	printf("--------------------------\n");
}

void	print_map(t_cub_data *data)
{
	int	i;

    printf("=== Entering map_printing ===\n");

	if (!data || !data->map.arr)
	{
		printf("Map is NULL or not initialized.\n");
		return ;
	}
	i = 0;
	while (data->map.arr[i])
	{
		printf("%s\n", data->map.arr[i]);
		i++;
	}
	printf("Map rows: %d\n", data->map.rows);
	printf("Map columns (max width): %d\n", data->map.columns);
}

void	print_cub_data(t_cub_data *data)
{
	if (!data)
	{
		printf("No data to print.\n");	
		return ;
	}
	printf("-----Texture Paths:\n");
	printf("  NO: %s\n", data->no_path);
	printf("  SO: %s\n", data->so_path);
	printf("  WE: %s\n", data->we_path);
	printf("  EA: %s\n", data->ea_path);
	printf("==========================\n");
	print_color("----Floor Color", data->floor_color);
	print_color("----Ceiling Color", data->ceiling_color);

	print_player(data);
	// printf("map rows %d\n",data->map.rows);
	// printf("map colo %d\n",data->map.columns);
	convert_char_arr_to_int_grid(&data->map);
	// print_map(data);
	print_int_map(data);
}
