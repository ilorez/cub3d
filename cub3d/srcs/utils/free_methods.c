/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:02:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/03 11:44:06 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
	free_cub_data(data->map_info);
}

void	free_tex(t_data *data, t_tex *tex)
{
	if (tex->loaded)
	{
		mlx_destroy_image(data->mlx, tex->img.img);
		free(tex->path);
		tex->loaded = 0;
	}
}

void	free_all_textures(t_data *data)
{
	int	i;

	i = -1;
	while (++i < TEX_COUNT)
	{
		if (data->tex[i].loaded)
		{
			mlx_destroy_image(data->mlx, data->tex[i].img.img);
			free(data->tex[i].path);
			data->tex[i].loaded = 0;
		}
	}
	i = -1;
	while (++i < TEX_PLA_COUNT)
	{
		if (data->pa.texs[i].loaded)
		{
			mlx_destroy_image(data->mlx, data->pa.texs[i].img.img);
			free(data->pa.texs[i].path);
			data->pa.texs[i].loaded = 0;
		}
	}
}
