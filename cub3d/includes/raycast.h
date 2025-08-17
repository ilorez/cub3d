/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:56:25 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/16 10:07:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

// include
# include "./container.h"

// functions
void	raycast(t_data *data);
void	raycast_cl(t_data *data, double ray_angl, int column);

// wall check
int		is_inlimit(t_cor f, t_data *data);
double	get_distance(t_cor a, t_cor b);
t_ray	horizontal_check(t_data *data, double ray_angl, int dh, int dv);
t_ray	vertical_check(t_data *data, double ray_angl, int dv);

#endif
