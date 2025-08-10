#ifndef PARSING_H
#define PARSING_H

#include "container.h"

// init cub data
void	init_cub_data(t_cub_data *data);

// parsing data function
int	parse_file_path(char *path, t_cub_data *data);

// texture pars
int	parse_texture_line(char *line, t_cub_data *data);

// colors pars
int	parse_color_line(char *line, t_cub_data *data);

/*---------------------VALIDATION---------------------*/
// main validation
int	validate_map(t_cub_data *data);

// MAP parsing 
int parse_map_lines(t_cub_data *data, int fd, char *first_line);

// MAP VALIDATION  
int validate_map(t_cub_data *data);
int is_valid_map_char(char c);

// FILE EXTENSION VALIDATION 
int	is_valid_cub_file(const char *filename);

/*++++++player validation++++++*/

int	validate_player_can_move(t_map *map,t_cub_data *cub_data);

/*--------------------HELPER FUNCTIONS-----------------*/

int	is_empty_line(char *line);
// remove new line cuz we dont need to skip it in split_whitespaces
void	remove_newline(char *line);

int	is_texture_line(char *line);

int	is_color_line(char *line);


/*++++++++++ MAP HELPER +++++++++*/
int	is_map_start(char *line);

int is_valid_map_char(char c);

int is_player_char(char c);

int is_walkable(char c);

int is_within_bounds(t_map *map, int row, int col);

// gets the efective line len by ignoring the last spaces
int get_effective_line_width(char *line);

/*++++ CLEAN UP  && DEBUG +++++ */
void	print_error_and_exit(const char *msg, t_cub_data *data, char *line, int fd);

// free string **str
void	free_str(char **str);



#endif