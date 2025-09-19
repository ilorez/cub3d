/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:46:23 by ablabib           #+#    #+#             */
/*   Updated: 2025/09/19 10:06:40 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"
#include <stdio.h>
#include <unistd.h>

int	validate_parsed_data(t_cub_data *data)
{
	if (!data->no_path || !data->so_path || !data->we_path || !data->ea_path)
		return (ft_handel_pars_exit(data, 3, 0),
			print_map_error("Missing texture path\n", -1, -1), 0);
	if (!is_valid_xpm_file(data->no_path) || !is_valid_xpm_file(data->so_path)
		|| !is_valid_xpm_file(data->we_path)
		|| !is_valid_xpm_file(data->ea_path))
		return (ft_handel_pars_exit(data, 3, 0),
			print_map_error("Invalid texture\n", -1, -1), 0);
	if (access(data->no_path, F_OK | R_OK) || access(data->so_path, F_OK | R_OK)
		|| access(data->we_path, F_OK | R_OK) || access(data->ea_path,
			F_OK | R_OK))
		return (ft_handel_pars_exit(data, 3, 0), perror(""),
			print_map_error("Invalid texture file\n", -1, -1), 0);
	if (!data->c_check || !data->f_check)
		return (ft_handel_pars_exit(data, 3, 0),
			print_map_error("Error\nMissing Ceiling or floor Color\n", -1, -1),
			0);
	if (!data->map.arr)
		return (ft_handel_pars_exit(data, 3, 0),
			print_map_error("Error\nMap not found\n", -1, -1), 0);
	if (!validate_map_bonus(data))
		return (ft_handel_pars_exit(data, 3, 0), 0);
	return (1);
}

static int	open_cub_file(char *path, t_cub_data *data)
{
	int	fd;

	if (!is_valid_cub_file(path))
		return (print_error_and_exit("Error\nInvalid File Extension\n", data,
				NULL, -1), -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("Cannot Open FILE:"), -1);
	return (fd);
}

static int	handle_texture_color(char *line, t_cub_data *data, int fd)
{
	if (is_texture_line(line) && !data->map_found)
	{
		if (!parse_texture_line(line, data))
		{
			ft_handel_pars_exit(data, 3, 0);
			print_error_and_exit("Error\nInvalid texture line\n", data, line,
				fd);
		}
	}
	else if (is_color_line(line) && !data->map_found)
	{
		if (!parse_color_line(line, data))
		{
			ft_handel_pars_exit(data, 3, 0);
			print_error_and_exit("Error\nInvalid color line\n", data, line, fd);
		}
	}
	else
		return (0);
	return (1);
}

static int	parse_line(char *line, t_cub_data *data, int fd)
{
	if (is_empty_line(line))
		return (1);
	if (handle_texture_color(line, data, fd))
		return (1);
	if (is_map_start(line))
	{
		if (!parse_map_lines(data, fd, line))
		{
			ft_handel_pars_exit(data, 3, 0);
			print_error_and_exit("Invalid map format\n", data, line, fd);
		}
		return (1);
	}
	return (ft_handel_pars_exit(data, 3, 0),
		print_error_and_exit("Unknown identifier in file\n", data, NULL, fd),
		0);
}

int	parse_file_path(char *path, t_cub_data *data)
{
	int		fd;
	char	*line;

	if (!path || !data)
		return (0);
	fd = open_cub_file(path, data);
	if (fd < 0)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!parse_line(line, data, fd))
			return (free(line), close(fd), 0);
		free(line);
	}
	close(fd);
	if (!validate_parsed_data(data))
		print_error_and_exit(NULL, data, NULL, -1);
	convert_char_arr_to_int_grid(&data->map);
	return (1);
}
