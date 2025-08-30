/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:29:58 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:29:59 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/container.h"

// validating the file extention (.cub)
int	is_valid_cub_file(const char *filename)
{
	int		len;
	char	**parts;
	char	*base;
	int		i;

	if (!filename)
		return (0);
	parts = NULL;
	base = (char *)filename;
	if (ft_strchr(filename, '/'))
	{
		parts = ft_split(filename, '/');
		if (!parts)
			return (0);
		i = 0;
		while (parts[i])
			i++;
		if (i == 0)
			return (free_str(parts), 0);
		base = parts[i - 1];
	}
	len = ft_strlen(base);
	if (len < 5 || ft_strncmp(base + len - 4, ".cub", 4) != 0)
		return (free_str(parts), 0);
	return (free_str(parts), 1);
}
