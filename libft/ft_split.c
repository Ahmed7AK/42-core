/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:54:38 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/13 18:08:54 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *str, char c)
{
	int	count;
	int	inword;
	int	i;

	count = 0;
	inword = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && !inword)
		{
			inword = 1;
			count++;
		}
		else if (str[i] == c)
			inword = 0;
		i++;
	}
	return (count);
}

static void	free_split(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*extract_word(char const **s, char c)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	while ((*s)[i] && (*s)[i] == c)
		i++;
	len = 0;
	while ((*s)[i + len] && (*s)[i + len] != c)
		len++;
	if (len == 0)
		return (NULL);
	*s += i;
	word = ft_substr(*s, 0, len);
	*s += len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	strs = malloc((words + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = 0;
	while (*s)
	{
		strs[i] = extract_word(&s, c);
		if (strs[i])
			i++;
		else if (*s)
		{
			free_split(strs, i);
			return (NULL);
		}
	}
	strs[i] = NULL;
	return (strs);
}
