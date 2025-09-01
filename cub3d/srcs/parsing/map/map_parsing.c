/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:35:50 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:42:50 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/container.h"

static void	calculate_map_dimensions(t_map *map)
{
	int	i;
	int	current_width;

	if (!map || !map->arr)
		return ;
	i = 0;
	map->columns = 0;
	while (map->arr[i])
	{
		current_width = get_effective_line_width(map->arr[i]);
		if (current_width > map->columns)
			map->columns = current_width;
		i++;
	}
	map->rows = i;
}

static int	append_line_to_map(t_str *map_str, char *line)
{
	char	*trimmed;

	trimmed = ft_rtrim(line);
	free(line);
	if (!trimmed)
		return (0);
	if (!str_append_list(map_str, trimmed))
	{
		free(trimmed);
		return (0);
	}
	free(trimmed);
	return (1);
}

static int	handle_map_line(t_str *map_str, char *line, int *map_ended)
{
	if (!*map_ended)
	{
		if (is_empty_line(line))
		{
			*map_ended = 1;
			free(line);
			return (1);
		}
		if (!append_line_to_map(map_str, line))
		{
			str_free(map_str);
			return (0);
		}
		return (1);
	}
	if (!is_empty_line(line))
	{
		str_free(map_str);
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

static int	finalize_map(t_cub_data *data, t_str *map_str)
{
	data->map.arr = ft_split(map_str->value, '\n');
	str_free(map_str);
	if (!data->map.arr)
		return (0);
	calculate_map_dimensions(&data->map);
	if (data->map.rows == 0)
		return (0);
	return (1);
}

int	parse_map_lines(t_cub_data *data, int fd, char *first_line)
{
	t_str	*map_str;
	char	*line;
	char	*trim;
	int		map_ended;

	if (!first_line || !*first_line)
		return (0);
	data->map_found = 1;
	map_ended = 0;
	trim = ft_rtrim(first_line);
	map_str = str_new(trim);
	free(trim);
	if (!map_str)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (!handle_map_line(map_str, line, &map_ended))
			return (0);
		line = get_next_line(fd);
	}
	if (!finalize_map(data, map_str))
		return (0);
	return (1);
}

/* main fix */
// int	parse_map_lines(t_cub_data *data, int fd, char *first_line)
// {
// 	t_str	*map_str;
// 	char	*line;
// 	char	*trim;
// 	if (!first_line || !*first_line)
// 		return (0);
// 	data->map_found = 1;
// 	trim = ft_rtrim(first_line);
// 	map_str = str_new(trim);
// 	free(trim);
// 	if (!map_str)
// 		return (0);
// 	while ((line = get_next_line(fd)))
// 		if (is_empty_line(line) || !append_line_to_map(map_str, line))
// 			return (free(line),str_free(map_str), 0);
// 	// check if there more thing after
// 	data->map.arr = ft_split(map_str->value, '\n');
// 	str_free(map_str);
// 	if (!data->map.arr)
// 		return (0);
// 	calculate_map_dimensions(&data->map);
// 	if (data->map.rows == 0)
// 		return (0);
// 	return (1);
// }

// int	parse_map_lines(t_cub_data *data, int fd, char *first_line)
// {
// 	t_str	*map_str;
// 	char	*line;

// 	if (!first_line || !*first_line)
// 		return (0);
// 	data->map_found = 1;
// 	map_str = str_new(ft_rtrim(first_line));
// 	free(first_line);
// 	if (!map_str)
// 		return (0);
// 	while ((line = get_next_line(fd)))
// 	{
// 		if (is_empty_line(line) || !append_line_to_map(map_str, line))
// 			return (str_free(map_str), 0);
// 	}
// 	data->map.arr = ft_split(map_str->value, '\n');
// 	str_free(map_str);
// 	if (!data->map.arr)
// 		return (0);
// 	calculate_map_dimensions(&data->map);
// 	if (data->map.rows == 0)
// 		return (0);
// 	return (1);
// }

// int parse_map_lines(t_cub_data *data, int fd, char *first_line)
// {
//     t_str    *map_str;
//     char     *line;
//     char     *r_trimed;
//     char     **map_arr;

//     if (!first_line || !*first_line)
//         return (0);
//     data->map_found = 1;
//     r_trimed = ft_rtrim(first_line);
//     if (!r_trimed)
//         return (0);
//     map_str = str_new(r_trimed);
//     free(r_trimed);
//     if (!map_str)
//         return (0);
//     while ((line = get_next_line(fd)))
//     {
//         if (is_empty_line(line))
//         {
//             free(line);
//             return (0);
//         }
//         r_trimed =  ft_rtrim(line);
//         free(line);
//         line = r_trimed;
//         if (!str_append_list(map_str, line))
//         {
//             free(line);
//             str_free(map_str);
//             return (0);
//         }
//         free(line);
//     }
//     map_arr = ft_split(map_str->value, '\n');
//     str_free(map_str);

//     if (!map_arr)
//         return (0);

//     data->map.arr = map_arr;

//     calculate_map_dimensions(&data->map);

//     if (data->map.rows == 0)
//     {
//         free_str(data->map.arr);
//         data->map.arr = NULL;
//         return (0);
//     }
//     return (1);
// }
