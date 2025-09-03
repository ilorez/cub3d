/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:46:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/03 10:49:04 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setup.h"

static int	load_xpm_to_tex(void *mlx, t_tex *tex, char *path)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	tex->loaded = 0;
	if (!mlx)
		ft_handel_exit(NULL, ERR_MLXINT);
	if (!path || !*path || access(path, F_OK) != 0)
		return (ft_serror(ERR_TEXMISS, (char *)path), 0);
	tex->img.img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
	if (!tex->img.img)
		return (ft_serror(ERR_TEXLOAD, (char *)path), 0);
	tex->img.addr = mlx_get_data_addr(tex->img.img, &tex->img.bpp, &tex->img.ll,
			&tex->img.endian);
	tex->img.w = w;
	tex->img.h = h;
	tex->path = path;
	tex->loaded = 1;
	return (1);
}

int	load_all_textures(t_data *data)
{
	t_cub_data	*m;

	m = (data->map_info);
	if (!m)
		return (0);
	load_xpm_to_tex(data->mlx, &data->tex[TEX_NO], m->no_path);
	load_xpm_to_tex(data->mlx, &data->tex[TEX_SO], m->so_path);
	load_xpm_to_tex(data->mlx, &data->tex[TEX_WE], m->we_path);
	load_xpm_to_tex(data->mlx, &data->tex[TEX_EA], m->ea_path);
	load_xpm_to_tex(data->mlx, &data->tex[TEX_DOOR], ft_strdup(DOOR_IMG));
	load_xpm_to_tex(data->mlx, &data->pa.texs[0], ft_strdup(PLAYER_IMG_1));
	load_xpm_to_tex(data->mlx, &data->pa.texs[1], ft_strdup(PLAYER_IMG_2));
	load_xpm_to_tex(data->mlx, &data->pa.texs[2], ft_strdup(PLAYER_IMG_3));
	load_xpm_to_tex(data->mlx, &data->pa.texs[3], ft_strdup(PLAYER_IMG_4));
	load_xpm_to_tex(data->mlx, &data->pa.texs[4], ft_strdup(PLAYER_IMG_5));
	return (1);
}
