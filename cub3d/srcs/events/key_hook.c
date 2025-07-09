/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:16:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 19:56:15 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/events.h"

int ft_check_move(int keycode)
{
  if (keycode != KEY_UP && keycode != KEY_DOWN && keycode != KEY_LEFT && keycode != KEY_RIGHT)
    return (0);
  // calculte new pos
  // check if it touch walls
  // move
  return (1);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		  ft_handle_window_exit(data, ERR_SUCCESS);
  if (keycode == KEY_UP)
    data->p.pos.y -= 10;
  else if (keycode == KEY_DOWN)
    data->p.pos.y += 10;
  else if (keycode == KEY_LEFT)
    data->p.pos.x -= 10;
  else if (keycode == KEY_RIGHT)
    data->p.pos.x += 10;
	return (0);
}
