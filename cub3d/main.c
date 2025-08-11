/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/11 11:20:50 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/container.h"

int main()
{
  t_data data;
  // parsing
  // get map

  ;
  data.map = generate_map(200, 200);
  ft_setup(&data);
  //render_map(data.map);
  //render_player(&data);
	mlx_loop(data.mlx);
}

