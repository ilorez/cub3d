/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:56:25 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 10:21:41 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

// include
# include "./container.h"

// functions
void	raycast(t_data *data);

// wall check
int		is_inlimit(t_cor f, t_data *data);
double	get_distance(t_cor a, t_cor b);

t_ray	horizontal_check(t_data *data, t_raycl_args a);
t_ray	vertical_check(t_data *data, t_raycl_args a);

// tetures
void	draw_wall_texture(t_data *data, t_ray r, int cl, t_tex *tex);

// get wall rect size
t_rect	get_wall_rect(t_data *data, t_ray r, int cl, double ray_angl);

#endif
