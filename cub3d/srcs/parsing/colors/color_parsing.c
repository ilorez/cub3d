#include "../includes/container.h"

static int	split_len(char **split)
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

	rgb = ft_split(value, ',');
	if (!rgb || split_len(rgb) != 3)
		return (free_str(rgb), 0);
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_str(rgb);
	if (color->r < 0 || color->r > 255 || color->g < 0
		|| color->g > 255 || color->b < 0 || color->b > 255)
		return (0);
	return (1);
}

int	parse_color_line(char *line, t_cub_data *data)
{
	char	**tokens;

	tokens = ft_split_whitespace(line);
	if (!tokens)
		return (0);
	if (ft_strncmp(tokens[0], "F", 1) == 0)
		return (fill_color(&data->floor_color, tokens[1]), free_str(tokens), 1);
	if (ft_strncmp(tokens[0], "C", 1) == 0)
		return (fill_color(&data->ceiling_color, tokens[1]), free_str(tokens), 1);
	return (free_str(tokens), 0);
}
