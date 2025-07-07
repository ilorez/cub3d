/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:13:23 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/07 14:13:24 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

// structs
typedef struct s_cor
{
	double		x;
	double		y;
}				t_cor;

typedef struct s_img_data
{
	void		*img;
	char		*addr;
	int			bpp;
	int			ll;
	int			endian;
}				t_img_data;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img_data	img_data;
  t_cor   px;
}				t_data;

#endif
