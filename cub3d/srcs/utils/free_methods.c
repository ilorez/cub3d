/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:02:20 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/22 15:52:16 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

void	ft_free_data(t_data *data)
{
	if (!data)
		return ;
}

void free_all_textures(t_data *data)
{
    t_cub_data *m; 

    m = data->map_info;
    for (int i = 0; i < TEX_COUNT; ++i)
    {
        if (data->tex[i].loaded)
        {
            mlx_destroy_image(data->mlx, data->tex[i].img.img);
            free(data->tex[i].path);
            data->tex[i].loaded = 0;
        }
    }
}
