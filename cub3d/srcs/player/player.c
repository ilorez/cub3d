/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:11:04 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 21:18:37 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

void render_player(t_data *data)
{
  t_cercl cercl;

  cercl.center = data->p.pos;
  cercl.radius = data->p.size;
  cercl.color = PLAYER_COLOR;
  render_filled_cercle(data->map->data, cercl);
}


