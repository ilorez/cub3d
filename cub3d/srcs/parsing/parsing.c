#include "../../includes/container.h"

// at the end we validate all the data parsed 
int	validate_parsed_data(t_cub_data *data)
{
	if (!data->no_path || !data->so_path || !data->we_path || !data->ea_path)
		return (0);
	// we could look for all the colors R,G,B : test it later
	if (data->floor_color.r < 0 || data->floor_color.r > 255 || 
		data->floor_color.g < 0 || data->floor_color.g > 255 || 
		data->floor_color.b < 0 || data->floor_color.b > 255 || 
		data->ceiling_color.r < 0 || data->ceiling_color.r > 255 || 
		data->ceiling_color.g < 0 || data->ceiling_color.g > 255 || 
		data->ceiling_color.b < 0 || data->ceiling_color.b > 255)
	{
		return (0);
	}
	if (!data->map.arr)
		return (0);
	
	// we can also add the map validation here instead of inside the parsing func
	// change this func (validate_map) => mandatory 
	// (validate_map_bonus) => bonus part
	if (!validate_map_bonus(data))
    {
        // printf("INVALID MAP!\n");
        free_str((char **)data->map.arr); 
        data->map.arr = NULL;
        return (0);
    }
	return (1);
}

// before parsing file path we should check for the extention (.cub) in the path
int	parse_file_path(char *path, t_cub_data *data)
{
	int		fd;
	char	*line;

	if (!path || !data)
		return 0;
	/* validate file extention (.cub) */
	if (!is_valid_cub_file(path))
		return (print_error_and_exit("Error\nInvalid File Extension\n",data,NULL,-1),0);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("Cant Open FILE:"),0);
		// print_error_and_exit("Error\nFailed to open .cub file\n", data, NULL,fd);

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
			if (!parse_map_lines(data, fd, line))
				return(print_error_and_exit("Error\nInvalid map format\n", data, line, fd),0);
		}
		else
			return(print_error_and_exit("Error\nUnknown identifier in file\n", data, line,fd),0);
		free(line);
	}
	close(fd);
	if (!validate_parsed_data(data))
		return 0;
		// return(print_error_and_exit("Error\nMissing or invalid elements\n", data, line, -1),0);
	return 1;
}

