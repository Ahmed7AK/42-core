/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 02:20:06 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/04 07:05:46 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char const *str, char c)
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

void	ft_free_split(char **strs, int count)
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
	while (i < words)
	{
		strs[i] = extract_word(&s, c);
		if (!strs[i])
		{
			ft_free_split(strs, i);
			return (NULL);
		}
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
