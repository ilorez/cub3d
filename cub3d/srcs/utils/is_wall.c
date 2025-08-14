/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:27:59 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/13 13:14:07 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

// translate x,y to map grid and see if it inside walls
int is_wall(t_cor *pos, t_data *data)
{
    int i,j;
    i = (int)floor(pos->x / (double)BLOCK_SIZE);
    j = (int)floor(pos->y / (double)BLOCK_SIZE);

    if (i < 0 || j < 0 || j >= data->map->rows || i >= data->map->columns)
        return 0;
    if ((data->map->arr)[j][i])
          return 1;
    return 0;
}

//int is_wall_old(t_cor *pos, t_data *data)
//{
//  int i,j;
//
//  i = (pos->x) / BLOCK_SIZE;
//  j = (pos->y) / BLOCK_SIZE;
//  if ((data->map->arr)[j][i])
//    return 1;
//  return 0;
//}


