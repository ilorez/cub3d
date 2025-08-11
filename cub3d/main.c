/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/11 14:23:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"
#include "debug/debug.h"
#include "includes/parsing.h"

int main(int ac,char **av)
{
  (void)ac;
  // t_data data;
  t_cub_data cub_data;
  // parsing

  // get map

  init_cub_data(&cub_data);
  parse_file_path(av[1], &cub_data);
  convert_char_arr_to_int_grid(&cub_data.map);
  print_int_map(&cub_data);
  //data.map = example_map();
  //ft_setup(&data);
  //render_map(data.map);
  //render_player(&data);
	//mlx_loop(data.mlx);
}

