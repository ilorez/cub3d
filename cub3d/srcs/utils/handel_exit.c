/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:02:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 13:11:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"
#include <stdlib.h>

void	ft_handel_exit(t_data *data, t_errno err)
{
	ft_free_data(data);
	if (err)
		ft_perror("Error", err);
	exit(err);
}

void	free_path(char *path)
{
	if (path)
		free(path);
}

void	ft_handel_pars_exit(t_cub_data *data, int err, int _exit)
{
	if (!data)
		return ;
	free_path(data->so_path);
	free_path(data->no_path);
	free_path(data->we_path);
	free_path(data->ea_path);
	free_cub_data(data);
	if (_exit)
		exit(err);
}

void	ft_handle_window_exit(t_data *data, t_errno err)
{
	mlx_destroy_image(data->mlx, data->map->data.img);
	mlx_destroy_image(data->mlx, data->img.img);
	free_all_textures(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_handel_exit(data, err);
}
