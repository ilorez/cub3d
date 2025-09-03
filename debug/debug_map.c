
#include "debug.h"

int main(void) {
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
		return 1;
	}

	// Print to check
	for (int i = 0; i < map->rows; i++) {
		for (int j = 0; j < map->columns; j++)
			printf("%d ", map->arr[i][j]);
		printf("\n");
	}

	// Free memory
	for (int i = 0; i < map->rows; i++)
		free(map->arr[i]);
	free(map->arr);
	free(map);

	return 0;
}
