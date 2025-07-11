/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:13:19 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/09 10:53:58 by znajdaou         ###   ########.fr       */
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

// free methods
void	ft_free_data(t_data *data);
// handel exit
void	ft_handel_exit(t_data *data, t_errno err);
void	ft_handle_window_exit(t_data *data, t_errno err);
#endif
