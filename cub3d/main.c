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
  (//void)ac;
  //t_cub_data data;
  // parsing

  // get map


  //init_cub_data(&cub_data);
  //parse_file_path(av[1], &cub_data);
  //convert_char_arr_to_int_grid(&cub_data.map);
  //print_int_map(&cub_data);
  //(void)av;
  // t_data data;

  /* bonus parsing test*/
  // init_cub_data(&data);
  //ft_memset(&data, 0, sizeof(data));
  //if(parse_file_path(av[1], &data))
  //  print_cub_data(&data);


  //free_cub_data(&data);


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

