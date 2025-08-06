/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:27:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/06 11:35:16 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

// translate x,y to map grid and see if it inside walls
int is_wall(t_cor pos, t_data *data)
{
  int i,j;

  i = (pos.x) / data->map->block_size;
  j = (pos.y) / data->map->block_size;
  if (i >= data->map->columns || j >= data->map->rows)
    return (0);
  if ((data->map->arr)[j][i])
    return 0;
  return 1;
}
