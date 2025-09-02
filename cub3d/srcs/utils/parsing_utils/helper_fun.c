/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablabib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 17:53:29 by ablabib           #+#    #+#             */
/*   Updated: 2025/08/30 17:53:30 by ablabib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/container.h"

// this would ignore the  spaces after a wall , for effective max width .
int	get_effective_line_width(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t'))
		len--;
	return (len);
}

void	remove_newline(char *line)
{
	size_t	len;

	if (!line)
		return ;
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	is_empty_line(char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (line[i] == '\0' || line[i] == '\n');
}

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

void	print_error_and_exit(const char *msg, t_cub_data *data, char *line,
		int fd)
{
	(void)data;
	if (line)
		free(line);
	if (fd >= 0)
	{
		clear_gnl(fd);
		close(fd);
	}
	free_cub_data(data);
	if (*msg || msg)
		ft_putstr_fd((char *)msg, 2);
	exit(1);
}
