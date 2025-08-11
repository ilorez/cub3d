/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/03 10:12:46 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"

int main(int ac,char **av)
{
  (void)ac;
  // t_data data;
  t_cub_data cub_data;
  // parsing
  // get map
  
  // data.map = example_map();
  // ft_setup(&data);
  // for parsing MAN bomboclat
  /*
  */
 init_cub_data(&cub_data);
 if(!parse_file_path(av[1], &cub_data))
    return (1);
  // converting **arr to (int) **grid
  convert_char_arr_to_int_grid(&cub_data.map);
 print_cub_data(&cub_data);
 // render_map(data.map);
  // render_player(&data);
	// mlx_loop(data.mlx);
}

