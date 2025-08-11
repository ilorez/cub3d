

#ifndef DEBUG_H
#define DEBUG_H

#include "../includes/container.h"
#include <stdio.h>

t_map *create_map_from_array(int rows, int columns, int input[rows][columns]);
t_map *generate_map(int rows, int columns);
t_map *example_map(void);
#endif

