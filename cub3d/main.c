/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/02 11:10:34 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"
#include "libft/includes/t_errno.h"

int main(int ac,char **av)
{
  t_cub_data pars_data;
  t_data data;

  if (ac != 2)
  {
      ft_perror(NULL, ERR_EARGS);
      exit(1);
  }
  (void)ac;
  /* bonus parsing test*/
  ft_memset(&pars_data, 0, sizeof(pars_data));
  if(parse_file_path(av[1], &pars_data))
    convert_char_arr_to_int_grid(&pars_data.map);
    // print_cub_data(&pars_data);
  // TODO
  
  
  // example data
  //pars_data = *example_usage2();
  // raycasting
  printf("Example ---:\n");
  printf("Player pos: (%d,%d)\n", pars_data.pos.x, pars_data.pos.y);
  printf("Angle: %f radians\n", pars_data.angle);
  printf("Floor color: (%d,%d,%d)\n",
         pars_data.floor_color.r, pars_data.floor_color.g, pars_data.floor_color.b);
  printf("Ceiling color: (%d,%d,%d)\n",
         pars_data.ceiling_color.r, pars_data.ceiling_color.g, pars_data.ceiling_color.b);
  printf("NO: %s\n", pars_data.no_path);
  printf("SO: %s\n", pars_data.so_path);
  printf("WE: %s\n", pars_data.we_path);
  printf("EA: %s\n", pars_data.ea_path);
  ft_setup(&data, &pars_data);
	mlx_loop(data.mlx);
}

