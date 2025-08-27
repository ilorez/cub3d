/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fake_pars_info.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2025/08/17 14:56:18 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 15:55:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./debug.h"

/* pars_info_factory.c Build a t_pars_info from a 2D array input[rows][cols].

   Assumes your typedefs exist exactly as you shared:
   - t_pars_info: has no_path, so_path, we_path, ea_path, angle, floor_color,
                  ceiling_color, pos (t_intcor), map (t_map), map_found
   - t_color, t_intcor, t_map (with int **grid, rows, columns, t_img_data data)
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ---- Example configur
 NO ./textures/simonkraft/wet_sponge.xpm
SO WE 
EA 

ation you can change later ---- */
#define NO_PATH "./textures/simonkraft/cobblestone.xpm"
#define SO_PATH "./textures/simonkraft/bookshelf.xpm"
#define WE_PATH "./textures/simonkraft/soul_sand.xpm"
#define EA_PATH "./textures/simonkraft/mycelium_top.xpm"
#define DOOR_PATH "./textures/door2.xpm"
#define PLAYER_PATH "./textures/egg.xpm"

//#define NO_PATH "./textures/test/north.xpm"
//#define SO_PATH "./textures/test/south.xpm"
//#define WE_PATH "./textures/test/west.xpm"
//#define EA_PATH "./textures/test/east.xpm"


#define ANGLEEE  (0)

/* ---- helpers ---- */
static void free_int_grid(int **grid, int rows) {
	if (!grid) return;
	for (int i = 0; i < rows; i++) free(grid[i]);
	free(grid);
}

/* Call this when you’re done with the struct to avoid leaks */
void	pars_info_destroy(t_cub_data *info) {
	if (!info) return;
	free(info->no_path);
	free(info->so_path);
	free(info->we_path);
	free(info->ea_path);
	free_int_grid(info->map.grid, info->map.rows);
	/* If you need to free map.data later, do it here once you own it. */
	free(info);
}

/*
 * Build from a VLA: const int input[rows][cols]
 * - Copies 0/1 as-is
 * - Finds a single '2' -> sets pos=(j,i), writes 0 into grid there
 * - Sets ceiling to aqua and floor to brown
 * - Sets angle to ANGLE (0)
 * - Duplicates path strings from the #defines above
 * Returns NULL on any error (allocation failure, or no '2' found).
 */
t_cub_data	*pars_info_create_from_array(int rows, int cols,
		const int input[rows][cols])
{
	if (rows <= 0 || cols <= 0 || !input)
		return NULL;

	t_cub_data *info = (t_cub_data *)calloc(1, sizeof(*info));
	if (!info) return NULL;

	/* Paths (duplicated so you can free/replace them later) */
	info->no_path = strdup(NO_PATH);
	info->so_path = strdup(SO_PATH);
	info->we_path = strdup(WE_PATH);
	info->ea_path = strdup(EA_PATH);
  info->door_path = strdup(DOOR_PATH);
  info->player_path = strdup(PLAYER_PATH);
	if (!info->no_path || !info->so_path || !info->we_path || !info->ea_path) {
		pars_info_destroy(info);
		return NULL;
	}

	/* Angle + colors */
	info->angle = ANGLEEE;
	info->ceiling_color = extract_color(COLOR_BLUE); /* aqua */
	info->floor_color   = extract_color(COLOR_RED);  /* brown */

	/* Map dims + allocate grid */
	info->map.rows = rows;
	info->map.columns = cols;
	info->map.grid = (int **)calloc(rows, sizeof(int *));
	if (!info->map.grid) {
		pars_info_destroy(info);
		return NULL;
	}

	bool found_player = false;

	for (int i = 0; i < rows; i++) {
		info->map.grid[i] = (int *)calloc(cols, sizeof(int));
		if (!info->map.grid[i]) {
			pars_info_destroy(info);
			return NULL;
		}
		for (int j = 0; j < cols; j++) {
			int v = input[i][j];
			if (v == 2) {
				/* First '2' sets player position; any extra '2's become 0 as well */
				if (!found_player) {
					info->pos.x = j;
					info->pos.y = i;
					found_player = true;
				}
				info->map.grid[i][j] = 0;
			} else {
				/* Expect 0 or 1; copy as-is */
				info->map.grid[i][j] = v;
			}
		}
	}

	/* Require at least one '2' for player start */
	if (!found_player) {
		pars_info_destroy(info);
		return NULL;
	}

	info->map_found = 1;
	return info;
}




/* Example usage */
void example_1(void)
{
    /* A tiny 5x5 test map
       Legend: 0 = empty, 1 = wall, 2 = player start
    */
    const int arr[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 2, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    t_cub_data *info = pars_info_create_from_array(5, 5, arr);
    if (!info) {
        printf("Failed to create pars_info!\n");
        return;
    }

    /* Print some fields to check */
    printf("Map size: %dx%d\n", info->map.rows, info->map.columns);
    printf("Player pos: (%d,%d)\n", info->pos.x, info->pos.y);
    printf("Angle: %f\n", info->angle);
    printf("Ceiling color: rgba(%u,%u,%u,%u)\n",
           info->ceiling_color.r, info->ceiling_color.g,
           info->ceiling_color.b, info->ceiling_color.a);
    printf("Floor color: rgba(%u,%u,%u,%u)\n",
           info->floor_color.r, info->floor_color.g,
           info->floor_color.b, info->floor_color.a);

    /* Show grid */
    printf("Map grid:\n");
    for (int i = 0; i < info->map.rows; i++) {
        for (int j = 0; j < info->map.columns; j++) {
            printf("%d ", info->map.grid[i][j]);
        }
        printf("\n");
    }

    /* Clean up */
    pars_info_destroy(info);
}

/* Example usage #2 */
t_cub_data *example_usage2(void)
{
    const int rows = 10;
    const int cols = 19;

    /* The map contains 'W' where the player starts.
       We'll write it as '2' here to reuse pars_info_create_from_array,
       but conceptually it comes from 'W'. */
    const int arr[10][19] = {
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1}, // 'W' replaced with 2
        {1,0,1,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0},
        {1,0,0,0,0,0,1,0,0,1,1,1,1,1,0,1,1,1,1},
        {1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1},
        {1,2,0,3,0,3,0,0,0,0,0,0,0,0,0,1,0,0,1},
        {1,0,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1},
        {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    t_cub_data *info = pars_info_create_from_array(rows, cols, arr);
    if (!info) {
        printf("Failed to create pars_info!\n");
        return (NULL);
    }

    /* Override colors from the file (F and C) */ 
    info->floor_color   = extract_color(COLOR_BROWN);
    info->ceiling_color = extract_color(COLOR_CYAN);

    /* Override texture paths */
    free(info->no_path);
    free(info->so_path);
    free(info->we_path);
    free(info->ea_path);
    info->no_path = strdup(NO_PATH);
    info->so_path = strdup(SO_PATH);
    info->we_path = strdup(WE_PATH);
    info->ea_path = strdup(EA_PATH);
    info->door_path = strdup(DOOR_PATH);
    info->player_path = strdup(PLAYER_PATH);

    info->angle = ANGLEEE;
    /* Print check */
    printf("Example 2:\n");
    printf("Player pos: (%d,%d)\n", info->pos.x, info->pos.y);
    printf("Angle: %f radians\n", info->angle);
    printf("Floor color: (%d,%d,%d)\n",
           info->floor_color.r, info->floor_color.g, info->floor_color.b);
    printf("Ceiling color: (%d,%d,%d)\n",
           info->ceiling_color.r, info->ceiling_color.g, info->ceiling_color.b);
    printf("NO: %s\n", info->no_path);
    printf("SO: %s\n", info->so_path);
    printf("WE: %s\n", info->we_path);
    printf("EA: %s\n", info->ea_path);
    return (info);

}
