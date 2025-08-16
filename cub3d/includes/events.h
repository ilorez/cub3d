/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:04:47 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/15 17:18:23 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// include
# include "./container.h"

// functions

// destroy
int	ft_destroy_event(t_data *data);

// loop
int	ft_loop_hook(t_data *data);

// key hook
int	ft_key_press(int keycode, t_data *data);
int	ft_key_release(int keycode, t_data *data);

// mouse click
int	ft_mouse_click(int key, int x, int y, t_data *data);
int	on_mouse_move(int x, int y, t_data *d);
int	on_mouse_enter(t_data *data);

#endif
