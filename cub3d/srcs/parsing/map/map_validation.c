#include "../includes/container.h"
#include <stdbool.h> // For using bool, true, false

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
    return (c == 'N' || c == 'E' || c == '1' || c == '0');
}

// Helper function to duplicate the map for safe checking
static char **duplicate_map(char **map, int rows)
{
    char **copy;
    int i = 0;

    copy = malloc(sizeof(char *) * (rows + 1));
    if (!copy)
        return (NULL);
    while (i < rows)
    {
        copy[i] = ft_strdup(map[i]);
        if (!copy[i])
        {
            // Free previously allocated strings on failure
            while (--i >= 0)
                free(copy[i]);
            free(copy);
            return (NULL);
        }
        i++;
    }
    copy[rows] = NULL;
    return (copy);
}

// The recursive flood fill function 💧
static bool check_enclosure_recursive(char **map_copy, int rows, int y, int x)
{
    // Get the width of the current row safely
    int width = ft_strlen(map_copy[y]);

    // 1. Base Case: Check for out-of-bounds or hitting a space.
    // This is the "leak" condition. If we reach the edge of the array
    // or a space, the map is open.
    if (y < 0 || y >= rows || x < 0 || x >= width || map_copy[y][x] == ' ')
        return (false); // ❌ Invalid: Map is open

    // 2. Base Case: If we hit a wall or an already checked path, stop.
    if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
        return (true); // ✅ Valid path, stop recursing here

    // 3. Mark the current spot as filled ('F') to avoid infinite loops
    map_copy[y][x] = 'F';

    // 4. Recursive Step: Check all 4 neighbors
    if (!check_enclosure_recursive(map_copy, rows, y + 1, x) ||
        !check_enclosure_recursive(map_copy, rows, y - 1, x) ||
        !check_enclosure_recursive(map_copy, rows, y, x + 1) ||
        !check_enclosure_recursive(map_copy, rows, y, x - 1))
    {
        return (false); // If any neighbor check fails, propagate the failure
    }

    return (true); // This path and all its children are valid
}

// Main validation function
int validate_map(t_cub_data *data)
{
    int y = 0;
    int x = 0;
    int player_count = 0;
    char **map_copy;

    // --- Step 1: Validate Characters & Player Position ---
    while (data->map.arr[y])
    {
        x = 0;
        while (data->map.arr[y][x])
        {
            char c = data->map.arr[y][x];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                player_count++;
                data->player.pos.y = y; // Store player position
                data->player.pos.x = x;
            }
            else if (c != '0' && c != '1' && c != ' ')
                return (0); // Invalid character
            x++;
        }
        y++;
    }
    if (player_count != 1)
        return (0); // Must be exactly one player
    data->map.rows = y;

    // --- Step 2: Validate Wall Enclosure using Flood Fill ---
    map_copy = duplicate_map(data->map.arr, data->map.rows);
    if (!map_copy)
        return (0); // Malloc failed

    if (!check_enclosure_recursive(map_copy, data->map.rows, data->player.pos.y, data->player.pos.x))
    {
        free_str(map_copy); // Free the copy
        return (0); // Enclosure check failed
    }

    free_str(map_copy); // Free the copy
    return (1); // ✅ Map is valid!
}