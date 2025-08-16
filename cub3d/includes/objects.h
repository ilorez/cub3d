/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:44:24 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/15 16:50:16 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

// include
# include "./container.h"

// functions
// line
void	render_line(t_img_data img, t_line *line);

// rect
int		render_rect(t_img_data img, t_rect rect);

// cercle
void	render_cercle(t_img_data img, t_cercl c);
void	render_filled_cercle(t_img_data img, t_cercl c);

// aim
void	render_aim(t_img_data img, int cx, int cy);

#endif
