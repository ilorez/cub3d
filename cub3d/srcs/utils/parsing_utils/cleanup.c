/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:49:37 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:50:02 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->arr)
	{
		free_split(map->arr);
		map->arr = NULL;
	}
	map->rows = 0;
	map->columns = 0;
}

void	free_converted_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map->grid[i])
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

void	free_cub_data(t_cub_data *data)
{
	if (!data)
		return ;
	free_map(&data->map);
	if (data->map.grid)
		free_converted_map(&data->map);
	data->map_found = 0;
}

// free **char str
void	free_str(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
