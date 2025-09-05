/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:35:51 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 13:07:27 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// include
# include "./container.h"
# include "types.h"

// functions
// mlx rewrite
char			*ft_mlx_get_data_addr(t_img_data *d);
void			ft_put_pixel(t_img_data img, t_cor cor, int color);
unsigned int	ft_get_pixel(t_img_data *img, int x, int y);
void			ft_mlx_put_image(t_img_data *dst, t_img_data *src,
					t_put_params params);

// free methods
void			ft_free_data(t_data *data);
void			free_all_textures(t_data *data);
void			free_tex(t_data *data, t_tex *tex);
// handel exit
void			ft_handel_exit(t_data *data, t_errno err);
void			ft_handle_window_exit(t_data *data, t_errno err);
void			ft_handel_pars_exit(t_cub_data *data, int err, int _exit);

// is wall
t_block_types	is_wall(t_cor *pos, t_data *data);

// door methods
void			toggle_door(t_data *data);
int				is_door(t_cor pos, t_data *data);

// color methods
int				ft_degree_color(double dist, int color);
int				merge_t_color(t_color c);
t_color			extract_color(int trgb);

// mouse utils
void			unlock_mouse(t_data *d);
void			lock_mouse(t_data *d);

// time now
time_t			ft_time_now(void);
#endif
