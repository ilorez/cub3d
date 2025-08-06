#include "../includes/container.h"

// at the end we validate all the data parsed 
int	validate_parsed_data(t_cub_data *data)
{
	if (!data->no_path || !data->so_path || !data->we_path || !data->ea_path)
		return (0);
	// we could look for all the colors R,G,B : test it later
	if (data->floor_color.r == -1 || data->ceiling_color.r == -1)
		return (0);
	// if (!data->map.grid)
	// 	return (0);
	return (1);
}

// before parsing file path we should check for the extention (.cub) in the path
void	parse_file_path(char *path, t_cub_data *data)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("Error\nFailed to open .cub file\n", data, NULL,fd);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (is_empty_line(line))
		{
			free(line);
			continue;
		}
		if (is_texture_line(line) && !data->map_found)
		{
			if (!parse_texture_line(line, data))
				print_error_and_exit("Error\nInvalid texture line\n", data, line,fd);
		}
		else if (is_color_line(line) && !data->map_found)
		{
			if (!parse_color_line(line, data))
				print_error_and_exit("Error\nInvalid color line\n", data, line, fd);
		}
		else if (is_map_start(line))
		{
			printf("found map\n");
			data->map_found = 1;
			// if (!parse_map_lines(data, fd, line))
			// 	print_error_and_exit("Error\nInvalid map format\n", data, line, fd);
			break ;
		}
		else
		{
			print_error_and_exit("Error\nUnknown identifier in file\n", data, line,fd);
			break;
		}
		// free(line);
	}
	close(fd);
	// if (!validate_parsed_data(data))
	// 	print_error_and_exit("Error\nMissing or invalid elements\n", data, line, -1);
}

// // giving the path of the .cub file
// void parse_file_path(char *path,t_cub_data *data)
// {
//     // t_cub_data *data;
//     int fd;
//     char *line;

//     fd = open(path, O_RDONLY);
//     if (!fd)
//         perror("failed to open fd");
//     // read the file line by line 
//     while(1)
//     {
//         line = get_next_line(fd);
//         if (!line)
//         {
//             printf("get_next_line failed to read\n");
//             break;
//         }
//         if (is_empty_line(line))
//             continue;
//         /*
//             #parsing texture CODE
//             #checking if the beginning of the line is "texture" 
//         */ 
//         if (is_texture_line(line) && !data->map_found)
//         {
//             // logic for parsing textures if return 0 error , 1 valid
//         }
//         /*
//             # parsing color CODE 
//             # checking if the beginning of the line is "colors"
//         */
//         else if (is_color_line(line) && !data->map_found)
//         {
//             // color parsing logic
//         }
//         /* 
//             #parsing MAP CODE
//             #checking if the map start here 
//         */
//         else if (is_map_start(line))
//         {
//             // data->map_found = 1; // set the flag for map found to 1 
//             // if (!parse_map_lines(data, fd, line))
//             // {
//             //      free(line);
//             //      close(fd);
//             //      print_error_and_exit("Error\nInvalid map");
//                 //  break; we need to break after we find the map;
//             //      return ;
//             // }
//             // If parse_map_lines consumes the rest, we might break here
//             // free(line); // Only if parse_map_lines took ownership
//             // break;
//             // Otherwise, continue loop if parse_map_lines just starts parsing
//         }
//         else
//         {
//             free(line);
//             close(fd);
//             print_error_and_exit("Error\nUnknown element in .cub file");
//             return ;
//         }
//         free(line);
//         line = NULL;
//     }

//     close(fd);
//     // validate the data look for (data->)
//     // if (!validate_parsed_data(data))
//     // {
//     //     print_error_and_exit("Error\nInvalid configuration data in .cub file");
//     //     return ;
//     // }
// }
