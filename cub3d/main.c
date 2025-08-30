/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 13:42:01 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"
#include "includes/types.h"

int main(int ac,char **av)
{
  (void)ac, (void)av;
  // example data
  t_cub_data *info;
  info  = example_usage2();
  // raycasting
  t_data data;
  data.last_fps_time = 0;
  ft_setup(&data, info);
	mlx_loop(data.mlx);
}

