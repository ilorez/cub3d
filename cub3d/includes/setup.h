/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 17:13:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/22 15:52:44 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

// include
# include "./container.h"

// functions
void	ft_setup(t_data *data, t_cub_data *info);

// load textures
int		load_all_textures(t_data *data);

#endif
