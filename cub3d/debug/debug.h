#ifndef DEBUG_H
#define DEBUG_H

#include "../includes/container.h"
#include <stdio.h>

t_map *create_map_from_array(int rows, int columns, int input[rows][columns]);
t_map *generate_map(int rows, int columns);
t_map *example_map(void);


/*----------PARSING DEBUG-------------*/
// printing cub data for parsing test
void	print_cub_data(t_cub_data *data);
// printing map for debugin 
void	print_map(t_cub_data *data);
// printing map int form 
void print_int_map(t_cub_data *data);

#endif

