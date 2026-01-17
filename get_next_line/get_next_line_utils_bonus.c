/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 12:03:08 by akheiral          #+#    #+#             */
/*   Updated: 2026/01/17 11:33:40 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*dup;
	int		i;

	if (!str)
		return (NULL);
	dup = malloc((ft_strlen(str) + 1) * sizeof(char));
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	i = 0;
	j = 0;
	while (str1[j])
		result[i++] = str1[j++];
	j = 0;
	while (str2[j])
		result[i++] = str2[j++];
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
	{
		substr = ft_strdup("");
		return (substr);
	}
	if (len > ft_strlen(str) - start)
		len = ft_strlen(str) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
