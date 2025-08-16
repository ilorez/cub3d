/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rtrim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:43:16 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/16 10:43:19 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_strncpy(char *dst, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dst[i] = '\0';
		i++;
	}
}

char	*ft_rtrim(char *line)
{
	int		len;
	char	*trimmed;

	if (!line)
		return (NULL);
	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t'))
		len--;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, line, len);
	trimmed[len] = '\0';
	return (trimmed);
}
