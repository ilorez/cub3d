/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 15:36:35 by znajdaou         ###   ########.fr       */
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
  ft_setup(&data, info);
	mlx_loop(data.mlx);
}

