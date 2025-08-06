#ifndef PARSING_H
#define PARSING_H

#include "container.h"

// init cub data
void	init_cub_data(t_cub_data *data);

// parsing data function
void	parse_file_path(char *path, t_cub_data *data);

// texture pars
int	parse_texture_line(char *line, t_cub_data *data);

// colors pars
int	parse_color_line(char *line, t_cub_data *data);


// helper functions 
int	is_empty_line(char *line);

int	is_texture_line(char *line);

int	is_color_line(char *line);

int	is_map_start(char *line);
// error printf func
void	print_error_and_exit(const char *msg, t_cub_data *data, char *line, int fd);
// free string **str
void	free_str(char **str);

#endif