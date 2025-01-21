/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:32:04 by sgabsi            #+#    #+#             */
/*   Updated: 2024/12/16 09:15:30 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*extract_word(const char *s, char c, size_t *len)
{
	const char	*start = s;

	while (*s && *s != c)
		s++;
	*len = s - start;
	return (ft_substr(start, 0, *len));
}

static void	ft_clear(char **tab, size_t index)
{
	for (size_t i = 0; i <= index; i++)
		free(tab[i]);
	free(tab);
}

static char	**ft_fill(const char *s, char c, char **result)
{
	char	**move;
	size_t	word_len;

	move = result;
	while (*s)
	{
		if (*s != c)
		{
			*move = extract_word(s, c, &word_len);
			if (!*move)
			{
				ft_clear(result, move - result);
				return (NULL);
			}
			move++;
			s += word_len;
		}
		else
			s++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	return (ft_fill(s, c, result));
}
