/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:16:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/04 13:45:02 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/events.h"

// translate x,y to map grid and see if it inside walls
int ft_is_valid_pos(t_cor pos, t_data *data)
{
  int i,j;

  i = (pos.x + data->p.size / 2.0)/ data->map->block_size;
  j = (pos.y + data->p.size / 2.0)/ data->map->block_size;
  if ((data->map->arr)[j][i])
    return 0;
  return 1;
}

int ft_check_move(int keycode, t_data *data)
{
  t_cor nextPos;
  // move player
  if (keycode == KEY_UP)
  {
    nextPos.x = data->p.pos.x +  data->p.speed * cos(data->p.angle);
    nextPos.y = data->p.pos.y + data->p.speed * sin(data->p.angle);
    if (ft_is_valid_pos(nextPos, data))
      data->p.pos = nextPos;
    return 1;
  }
  else if (keycode == KEY_DOWN)
  {
    data->p.pos.x -= data->p.speed * cos(data->p.angle);
    data->p.pos.y -= data->p.speed * sin(data->p.angle);
    return 1;
  }
  else if (keycode == KEY_LEFT)
  {
    data->p.angle -= data->p.rs;
    return 1;
  }

  else if (keycode == KEY_RIGHT)
  {
    data->p.angle += data->p.rs;
    return 1;
  }
  return 0;
}


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

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		    ft_handle_window_exit(data, ERR_SUCCESS);
  else if (ft_check_move(keycode, data))
    ;
  else if (ft_update_settings(keycode, data))
    ;
	return (0);
}
