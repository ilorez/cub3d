/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:57:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/09/19 10:19:03 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/container.h"

static int	init_data_and_pars(char *av, t_cub_data *pars_data);

int	main(int ac, char **av)
{
	t_cub_data	pars_data;
	t_data		data;

	if (ac != 2)
	{
		ft_perror(NULL, ERR_EARGS);
		exit(ERR_EARGS);
	}
	if (init_data_and_pars(av[1], &pars_data))
	{
		ft_setup(&data, &pars_data);
		mlx_loop(data.mlx);
	}
	return (EXIT_SUCCESS);
}

static int	init_data_and_pars(char *av, t_cub_data *pars_data)
{
	ft_memset(pars_data, 0, sizeof(*pars_data));
	return (parse_file_path(av, pars_data));
}
