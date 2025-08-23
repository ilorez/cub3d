/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:35:51 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/22 16:23:54 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// include
# include "./container.h"

// functions
// mlx rewrite
char	*ft_mlx_get_data_addr(t_img_data *d);
void	ft_put_pixel(t_img_data img, t_cor cor, int color);
inline unsigned int ft_get_pixel(t_img_data *img, int x, int y);

// free methods
void	ft_free_data(t_data *data);
// handel exit
void	ft_handel_exit(t_data *data, t_errno err);
void	ft_handle_window_exit(t_data *data, t_errno err);

// is wall
int		is_wall(t_cor *pos, t_data *data);

// color methods
int		ft_degree_color(double dist, int color);
int	merge_t_color(t_color c);
t_color	extract_color(int trgb);

// mouse utils
void	unlock_mouse(t_data *d);
void	lock_mouse(t_data *d);
#endif
