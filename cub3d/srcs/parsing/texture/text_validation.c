/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:47:23 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:47:25 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.h"

int	is_texture_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	return (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
		|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0);
}
// static int	ft_strcmp(const char *s1, const char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while ((unsigned char)s1[i] == (unsigned char)s2[i]
// 		&& s1[i] != '\0' && s2[i] != '\0')
// 		i++;
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }
