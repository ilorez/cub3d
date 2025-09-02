/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/29 10:39:21 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

// include
# include "./container.h"

void	handle_keyboard_move(t_data *data, double step, double cosA,
			double sinA);
void	handle_view(t_data *data, double dt);
// functions
void	render_player(t_data *data);

// animation
void	pl_animation_update(t_pl_animation *pa);
void	render_player_skin(t_data *d);
void	handel_jump(t_data *data);
#endif
