/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:46:00 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/27 10:34:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/setup.h"

static int load_xpm_to_tex(void *mlx, t_tex *tex, const char *path)
{
    int w;
    int h;

    h = 0;
    w = 0;
    if (!mlx)
    {
      fprintf(stderr, "mlx not initialized!\n");
      exit(1);
    }
    if (!path || !*path)
        return 0;

    if (access(path, F_OK) != 0)
      fprintf(stderr, "missing texture file: %s\n", path);
    tex->img.img = mlx_xpm_file_to_image(mlx, (char *)path, &w, &h);
    if (!tex->img.img)
    {
        //TODO: use stderr
        printf("texture load failed: %s\n", path);
        tex->loaded = 0;
        return 0;
    }
    tex->img.addr = mlx_get_data_addr(tex->img.img,
                                      &tex->img.bpp,
                                      &tex->img.ll,
                                      &tex->img.endian);
    tex->img.w = w;
    tex->img.h = h;
    tex->path = ft_strdup(path);
    tex->loaded = 1;
    return 1;
}

int load_all_textures(t_data *data)
{
    t_cub_data *m;

    m = (data->map_info);
    if (!m)
      return 0;
    load_xpm_to_tex(data->mlx, &data->tex[TEX_NO], m->no_path);
    load_xpm_to_tex(data->mlx, &data->tex[TEX_SO], m->so_path);
    load_xpm_to_tex(data->mlx, &data->tex[TEX_WE], m->we_path);
    load_xpm_to_tex(data->mlx, &data->tex[TEX_EA], m->ea_path);
    load_xpm_to_tex(data->mlx, &data->tex[TEX_DOOR], m->door_path);
    load_xpm_to_tex(data->mlx, &data->tex[TEX_PLAYER], m->player_path);
    return 1;
}
