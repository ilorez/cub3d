/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:12:08 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/03 11:44:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/utils.h"

// lock mouse and hide it and move it to center with ingoring this move
//mlx_mouse_hide(d->mlx, d->win);
void	lock_mouse(t_data *d)
{
	d->mouse.lock = 1;
	mlx_mouse_move(d->mlx, d->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	d->mouse.ignore_next_move = 1;
}

void	unlock_mouse(t_data *d)
{
	mlx_mouse_show(d->mlx, d->win);
	d->mouse.lock = 0;
}
