/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:50:33 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:51:05 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/container.h"

static void	free_int_grid(int **grid, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

static int	char_to_int(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (2);
	if (c == 'D')
		return (3);
	if (c == ' ')
		return (4);
	return (-1);
}

int	convert_char_arr_to_int_grid(t_map *map)
{
	int	i;
	int	j;

	map->grid = ft_calloc(sizeof(int *), map->rows + 1);
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->grid[i] = ft_calloc(sizeof(int),
				(get_effective_line_width(map->arr[i])) + 1);
		if (!map->grid[i])
		{
			free_int_grid(map->grid, i);
			map->grid = NULL;
			return (0);
		}
		j = 0;
		while (j < get_effective_line_width(map->arr[i]))
		{
			map->grid[i][j] = char_to_int(map->arr[i][j]);
			j++;
		}
		i++;
	}
	return (1);
}
