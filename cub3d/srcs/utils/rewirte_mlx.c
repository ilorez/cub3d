/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rewirte_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:02:14 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/03 10:55:05 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

char	*ft_mlx_get_data_addr(t_img_data *d)
{
	return (mlx_get_data_addr(d->img, &d->bpp, &d->ll, &d->endian));
}

void	ft_put_pixel(t_img_data img, t_cor cor, int color)
{
	char	*dst;

	dst = img.addr + (int)cor.y * img.ll + (int)cor.x * (img.bpp / 8);
	*(unsigned int *)dst = color;
}
