/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:29:27 by ablabib           #+#    #+#             */
/*   Updated: 2025/09/19 10:16:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/container.h"

static int	colors_count(char **split)
{
	int	len;

	len = 0;
	if (!split)
		return (0);
	while (split[len])
		len++;
	return (len);
}

static int	fill_color(t_color *color, char *value)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (!color || !value)
		return (0);
	rgb = ft_split(value, ',');
	if (!rgb || colors_count(rgb) != 3)
		return (free_str(rgb), 0);
	if (is_empty_line(rgb[0]) || is_empty_line(rgb[1]) || is_empty_line(rgb[2]))
		return (free_str(rgb), 0);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_str(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);
	color->r = (unsigned char)r;
	color->g = (unsigned char)g;
	color->b = (unsigned char)b;
	color->a = 255;
	return (1);
}

int	parse_color_line(char *line, t_cub_data *data)
{
	char	**tokens;
	int		result;

	tokens = ft_split_whitespace(line);
	if (!tokens)
		return (0);
	result = 0;
	if (ft_strncmp(tokens[0], "F", 2) == 0)
	{
		if (tokens[1])
			result = fill_color(&data->floor_color, tokens[1]);
		data->f_check = result;
	}
	else if (ft_strncmp(tokens[0], "C", 2) == 0)
	{
		if (tokens[1])
			result = fill_color(&data->ceiling_color, tokens[1]);
		data->c_check = result;
	}
	free_str(tokens);
	return (result);
}
