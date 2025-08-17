/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 16:33:22 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/16 12:01:16 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

void	render_aim(t_img_data img, int cx, int cy)
{
	int (len), (gap), (t), (x), (y), (c);
	c = AIM_COLOR;
	len = AIM_SIZE;
	gap = AIM_CENTER_GAP;
	t = -AIM_THICK / 2;
	while (++t <= AIM_THICK / 2)
	{
		x = cx - len;
		y = cy - len;
		while (++x <= cx - gap)
			ft_put_pixel(img, (t_cor){x, cy + t}, c);
		while (++y <= cy - gap)
			ft_put_pixel(img, (t_cor){cx + t, y}, c);
		x = cx + gap;
		y = cy + gap;
		while (++x <= cx + len)
			ft_put_pixel(img, (t_cor){x, cy + t}, c);
		while (++y <= cy + len)
			ft_put_pixel(img, (t_cor){cx + t, y}, c);
	}
}
