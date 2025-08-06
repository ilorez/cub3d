#include "../includes/container.h"

// static void print_texture(char *text,char *path)
// {
// 	printf("%s => [%s]\n",text,path);
// }
int	parse_texture_line(char *line, t_cub_data *data)
{
	char	**tokens;

	tokens = ft_split_whitespace(line);
	if (!tokens)
		return (0);
	if (ft_strncmp(tokens[0], "NO", 2) == 0 && !data->no_path)
		data->no_path = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "SO", 2) == 0 && !data->so_path)
		data->so_path = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "WE", 2) == 0 && !data->we_path)
		data->we_path = ft_strdup(tokens[1]);
	else if (ft_strncmp(tokens[0], "EA", 2) == 0 && !data->ea_path)
		data->ea_path = ft_strdup(tokens[1]);
	else
		return (free_str(tokens), 0);
	return (free_str(tokens), 1);
}
