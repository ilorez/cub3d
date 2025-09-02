/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:47:15 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:47:17 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.h"

int	parse_texture_line(char *line, t_cub_data *data)
{
	char	**tokens;

	if (!line || !data)
		return (0);
	remove_newline(line);
	tokens = ft_split_whitespace(line);
	if (!tokens || !tokens[0])
		return (free_str(tokens), 0);
	if (!tokens[1])
		return (free_str(tokens), 0);
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
