/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:27:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/08 15:43:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

// translate x,y to map grid and see if it inside walls
int is_wall(t_cor *pos, t_data *data)
{
  int i,j;

  i = (pos->x) / data->map->bs;
  j = (pos->y) / data->map->bs;
  //if (i < 0)
  //  pos->x = 0;
  //if (j < 0)
  //  pos->y = 0;
  //if (pos->x >= WIN_WIDTH)
  //  pos->x = WIN_WIDTH - 1;
  //if (pos->y >= WIN_HEIGHT)
  //  pos->y = WIN_HEIGHT - 1;
  //if (i >= data->map->columns || j >= data->map->rows || i <= 0 || j <= 0)
   // return (1);
  if ((data->map->arr)[j][i])
    return 1;
  return 0;
}
