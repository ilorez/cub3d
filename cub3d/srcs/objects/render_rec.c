/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:56 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/12 10:45:06 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/objects.h"

int render_rect(t_img_data img, t_rect rect)
{
  t_cor cor;
  double y;

	cor.x = rect.pos.x;
  y = rect.pos.y;
  if (cor.x < 0)
    cor.x = 0;
  if (y < 0)
    y = 0;
	while (cor.x < rect.pos.x + rect.width && cor.x < WIN_WIDTH)
	{
		cor.y = y;
		while (cor.y < rect.pos.y + rect.height && cor.y < WIN_HEIGHT)
    {
      ft_put_pixel(img, cor, rect.color);
      cor.y++;
    }
		++(cor.x);
	}
	return (0);
}

