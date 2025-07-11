/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 10:53:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 11:19:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "debug.h"

t_map *create_map_from_array(int rows, int columns, int input[rows][columns]) {
	t_map *map = malloc(sizeof(t_map));
	if (!map)
		return NULL;

	map->rows = rows;
	map->columns = columns;

	map->arr = malloc(sizeof(int *) * rows);
	if (!map->arr) {
		free(map);
		return NULL;
	}

	for (int i = 0; i < rows; i++) {
		map->arr[i] = malloc(sizeof(int) * columns);
		if (!map->arr[i]) {
			for (int j = 0; j < i; j++)
				free(map->arr[j]);
			free(map->arr);
			free(map);
			return NULL;
		}
		for (int j = 0; j < columns; j++) {
			map->arr[i][j] = input[i][j];
		}
	}

	return map;
}


t_map *example_map(void) {

	int worldMap[8][12] = {
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,0,1,0,0,1},
		{1,0,0,1,0,0,1,0,1,0,0,1},
		{1,0,0,0,0,0,1,0,1,0,0,1},
		{1,0,0,0,0,0,1,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};

	t_map *map = create_map_from_array(8, 12, worldMap);
	if (!map) {
		printf("Failed to create map\n");
		return NULL;
	}

	// Print to check
	for (int i = 0; i < map->rows; i++) {
		for (int j = 0; j < map->columns; j++)
			printf("%d ", map->arr[i][j]);
		printf("\n");
	}
  return (map);
}
