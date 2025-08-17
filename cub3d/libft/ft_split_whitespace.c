/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 10:45:11 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/16 10:45:13 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r');
}

static int	count_words(char *str)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_whitespace(*str))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

static char	*malloc_word(char *start, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **words, int i)
{
	while (--i >= 0)
		free(words[i]);
	free(words);
}

char	**ft_split_whitespace(char *str)
{
	char	**words;
	int		i;
	int		len;

	words = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!words)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && is_whitespace(*str))
			str++;
		len = 0;
		while (str[len] && !is_whitespace(str[len]))
			len++;
		if (len > 0)
		{
			words[i] = malloc_word(str, len);
			if (!words[i++])
				return (free_all(words, i), NULL);
			str += len;
		}
	}
	words[i] = NULL;
	return (words);
}
