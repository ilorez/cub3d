/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:53:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 12:35:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "debug.h"
#include <stdlib.h>
#include <time.h>

t_map *generate_map(int rows, int columns) {
    t_map *map = malloc(sizeof(t_map));
    if (!map)
        return NULL;

    map->rows = rows;
    map->columns = columns;

    map->grid = malloc(sizeof(int *) * rows);
    if (!map->arr) {
        free(map);
        return NULL;
    }

    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        map->grid[i] = malloc(sizeof(int) * columns);
        if (!map->grid[i]) {
            for (int j = 0; j < i; j++)
                free(map->grid[j]);
            free(map->grid);
            free(map);
            return NULL;
        }

        for (int j = 0; j < columns; j++) {
            // Borders = wall
            if (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) {
                map->grid[i][j] = 1;
            }
            // Inside = random
            else {
                map->grid[i][j] = (rand() % 10 > 2) ? 0 : 0; 
                // 70% chance of wall, 30% path
            }
        }
    }

    return map;
}

