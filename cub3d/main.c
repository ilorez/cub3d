/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/07 17:00:48 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"
#include "includes/settings.h"

int	ft_create_mlx_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_handel_exit(data, ERR_MLX_FIELDCON);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract-ol");
	data->map.img = mlx_new_image(data->mlx, MAP_WIDTH, MAP_HEIGHT);
	data->map.addr = ft_mlx_get_data_addr(&data->map);
	mlx_hook(data->win, 17, 1L, ft_destroy_event, data);
	mlx_hook(data->win, 2, 1L, ft_key_hook, data);
	mlx_mouse_hook(data->win, ft_mouse_click, data);
	mlx_loop_hook(data->mlx, ft_loop_hook, data);
	return (true);
}

int main()
{
  t_data data;
  
  ft_create_mlx_window(&data);
	mlx_loop(data.mlx);
}

