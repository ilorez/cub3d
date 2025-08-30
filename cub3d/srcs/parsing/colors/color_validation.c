/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:29:39 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:29:41 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.h"

int	is_color_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (ft_strncmp(line, "F", 1) == 0 || ft_strncmp(line, "C", 1) == 0);
}

int	is_valid_color_form(char *color_str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (color_str[i])
	{
		if (color_str[i] == ',')
			comma_count++;
		else if (!ft_isdigit(color_str[i]) && color_str[i] != ' ')
			return (0);
		i++;
	}
	return (comma_count == 2);
}
