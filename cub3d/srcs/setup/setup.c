/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:19:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 19:53:59 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setup.h"

void ft_setup_map(t_map *map)
{
  map->block_size = MAX_MAP_WIDTH / map->columns;
  if (map->block_size > MAX_MAP_HEIGHT / map->rows)
    map->block_size = MAX_MAP_HEIGHT / map->rows;
  map->width = map->block_size * map->columns;
  map->hieght = map->block_size * map->rows;
}

void ft_setup_player (t_data *data)
{
  int ps = data->map->block_size/4;
  if (ps < 1)
    ps = 1;
  data->p.pos.x = 50;
  data->p.pos.y = 50;
  data->p.size = ps;
  data->p.angle = 0;
  data->p.dx = cos(0) * 5;
  data->p.dy = sin(0) * 5;
}

int	ft_create_mlx_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_handel_exit(data, ERR_MLX_FIELDCON);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
	data->map->data.img = mlx_new_image(data->mlx, data->map->width, data->map->hieght);
	data->map->data.addr = ft_mlx_get_data_addr(&data->map->data);
	mlx_hook(data->win, 17, 1L, ft_destroy_event, data);
	mlx_hook(data->win, 2, 1L, ft_key_hook, data);
	mlx_mouse_hook(data->win, ft_mouse_click, data);
	mlx_loop_hook(data->mlx, ft_loop_hook, data);
	return (true);
}

void ft_setup(t_data *data)
{
  ft_setup_map(data->map);
  ft_setup_player(data);
  ft_create_mlx_window(data);
}
