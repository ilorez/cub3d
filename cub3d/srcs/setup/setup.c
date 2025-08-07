/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:19:55 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/07 18:43:30 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setup.h"
#include <stdio.h>

void ft_setup_map(t_map *map)
{
  map->bs = MAX_MAP_WIDTH / map->columns;
  if (map->bs > MAX_MAP_HEIGHT / map->rows)
    map->bs = MAX_MAP_HEIGHT / map->rows;
  map->width = map->bs * map->columns;
  map->hieght = map->bs * map->rows;
}

void ft_setup_player (t_data *data)
{
  int ps = data->map->bs/4;
  if (ps < 1)
    ps = 1;
  if (ps > 5)
    ps = 5;
  data->p.pos.y = (double)(data->map->bs) * 3/2;
  data->p.pos.x = (double)(data->map->bs) * 3/2;
  data->p.size = ps;
  data->p.angle =1.5 * PI;
  data->p.dx = 0;
  data->p.dy = 0;
  data->p.rs = ROTATION_SPEED_DEG * (PI);
  data->p.speed = (data->map->bs * 2) * PLAYER_SPEED;
  data->p.sp_inc =  data->map->bs / 2.0;
  data->p.sp_max =  data->map->bs * 10.0;
  data->p.sp_min =  data->map->bs / 10.0;
}

int	ft_create_mlx_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_handel_exit(data, ERR_MLX_FIELDCON);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Fract-ol");
  data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->map->data.img = mlx_new_image(data->mlx, data->map->width, data->map->hieght);
	data->map->data.addr = ft_mlx_get_data_addr(&data->map->data);
	data->img.addr = ft_mlx_get_data_addr(&data->img);
	mlx_hook(data->win, 17, 0L, ft_destroy_event, data);
	mlx_hook(data->win, ON_KEYDOWN, (1L<<0), ft_key_press, data);
	mlx_hook(data->win, ON_KEYUP, (1L<<1), ft_key_release, data);
	mlx_mouse_hook(data->win, ft_mouse_click, data);
	mlx_loop_hook(data->mlx, ft_loop_hook, data);
	return (true);
}

void ft_setup(t_data *data)
{
  ft_setup_map(data->map);
  ft_setup_player(data);
  data->lastf = 0;
  ft_create_mlx_window(data);
}
