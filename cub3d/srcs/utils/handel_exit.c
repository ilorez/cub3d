/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:02:31 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/07 14:02:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_handel_exit(t_data *data, t_errno err)
{
	ft_free_data(data);
	if (err)
		ft_perror("Error", err);
	exit(err);
}

void	ft_handle_window_exit(t_data *data, t_errno err)
{
	mlx_destroy_image(data->mlx, data->img_data.img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_handel_exit(data, err);
}
