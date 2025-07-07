/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:16:35 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/07 15:17:00 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/events.h"

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		ft_handle_window_exit(data, ERR_SUCCESS);
	return (0);
}
