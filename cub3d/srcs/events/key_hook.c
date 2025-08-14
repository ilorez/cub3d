/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:16:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/13 11:51:52 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/events.h"
#include <stdlib.h>

int ft_update_settings(int keycode, t_data *data)
{
  // update rotaion speed
  if (keycode == KEY_RSUP)
  {
    data->p.rs += ROTATION_SPEED_INC;
    if (data->p.rs > ROTATION_SPEED_MAX)
      data->p.rs = ROTATION_SPEED_MAX;
    return 1;
  }
  if (keycode == KEY_RSDOWN)
  {
    data->p.rs -= ROTATION_SPEED_INC;
    if (data->p.rs < ROTATION_SPEED_MIN)
      data->p.rs = ROTATION_SPEED_MIN;
    return 1;
  }
  if (keycode == KEY_SPUP)
  {
    data->p.speed += data->p.sp_inc;
    if (data->p.speed > data->p.sp_max)
      data->p.speed = data->p.sp_max;
    return 1;
  }
  if (keycode == KEY_SPDOWN)
  {
    data->p.speed -= data->p.sp_inc;
    if (data->p.speed < data->p.sp_min)
      data->p.speed = data->p.sp_min;
    return 1;
  }
  return 0;
}

int ft_key_press(int keycode, t_data *data)
{
  if (keycode == KEY_ESC)
		    ft_handle_window_exit(data, ERR_SUCCESS);
  if (keycode == KEY_MUP)
    data->p.dy = 1;
  else if (keycode == KEY_MDOWN)
    data->p.dy = -1;
  else if (keycode == KEY_MRIGHT)
    data->p.dh = 1;
  else if (keycode == KEY_MLEFT)
    data->p.dh = -1;
  else if (keycode == KEY_UP)
      data->p.dv = 1;
  else if (keycode == KEY_DOWN)
      data->p.dv = -1;
  else if (keycode == KEY_LEFT)
    data->p.dx = -1;
  else if (keycode == KEY_RIGHT)
    data->p.dx = 1;
  else if (ft_update_settings(keycode, data))
    {
      
    }
  return (EXIT_SUCCESS);
}

int ft_key_release(int keycode, t_data *data)
{
  //printf("release up :%d\n", keycode);
  if (keycode == KEY_MUP || keycode == KEY_MDOWN)
    data->p.dy = 0;
  else if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
    data->p.dx = 0;
  else if (keycode == KEY_MLEFT || keycode == KEY_MRIGHT)
    data->p.dh = 0;
  else if (keycode == KEY_UP || keycode == KEY_DOWN)
    data->p.dv = 0;
  return (EXIT_SUCCESS);
}
