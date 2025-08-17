/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 12:46:39 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"

int main(int ac,char **av)
{
  (void)ac;
  t_cub_data cub_data;
  // parsing
  // get map
  init_cub_data(&cub_data);
  if (!parse_file_path(av[1], &cub_data))
    return (printf("Error\nNo Map.\n"), 1);
  convert_char_arr_to_int_grid(&cub_data.map);
  //print_int_map(&cub_data);

  // raycasting
  t_data data;
  data.map = &(cub_data.map);
  data.map_info = cub_data;
  //data.map = generate_map(8, 8);
  //data.map = example_map();
  printf("map rows is: %d\n", data.map->rows);
  printf("map columns is: %d\n", data.map->columns);
  ft_setup(&data, cub_data);
  //render_map(&data, data.map);
  //ft_bzero(data->img.addr, WIN_WIDTH * WIN_HEIGHT * (data->img.bpp / 8));
  //render_fc(&data);
  //raycast(data);
  //render_player(&data);
	mlx_loop(data.mlx);
}

