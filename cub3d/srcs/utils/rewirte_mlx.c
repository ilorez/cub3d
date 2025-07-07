/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewirte_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:02:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/07 14:02:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_mlx_get_data_addr(t_img_data *d)
{
	return (mlx_get_data_addr(d->img, &d->bpp, &d->ll, &d->endian));
}

void	ft_put_pixel(t_img_data *data, t_cor *cor, int color)
{
	char	*dst;

	dst = data->addr + (int)(cor->y * data->ll + cor->x * ((double)data->bpp / 8));
	*(unsigned int *)dst = color;
}
