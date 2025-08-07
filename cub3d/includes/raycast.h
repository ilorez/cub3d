/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:56:25 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/07 17:18:40 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAT_H
#define RAYCAT_H

// include
#include "./container.h"

// functions
void raycast(t_data *data);
void raycast_cl(t_data *data, double ray_angl);

// wall check
int is_inlimit(t_cor f, t_data *data);
double get_distance(t_cor a, t_cor b);
t_ray horizontal_check(t_data *data, double ray_angl, t_ray r);
t_ray vertical_check(t_data *data, double ray_angl, t_ray r);
#endif
