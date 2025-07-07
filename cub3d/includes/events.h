/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:04:47 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/07 15:17:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// include
#include "./container.h"

// functions

// destroy
int	ft_destroy_event(t_data *data);

// loop
int	ft_loop_hook(t_data *data);

// key hook
int	ft_key_hook(int keycode, t_data *data);

#endif
