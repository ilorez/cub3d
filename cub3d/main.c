/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/02 11:01:32 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"
#include "includes/parsing.h"
#include "includes/types.h"

int main(int ac,char **av)
{
  (void)ac;
  t_cub_data pars_data;

  /* bonus parsing test*/
  ft_memset(&pars_data, 0, sizeof(pars_data));
  if(parse_file_path(av[1], &pars_data))
    print_cub_data(&pars_data);
  convert_char_arr_to_int_grid(&pars_data.map);

  // TODO
  //free_cub_data(&data);
  (void)ac, (void)av;
  // example data
  //t_cub_data *info;
  //info  = example_usage2();
  // raycasting
  t_data data;
  data.last_fps_time = 0;
  ft_setup(&data, &pars_data);
	mlx_loop(data.mlx);
}

