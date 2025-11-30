/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:37:07 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/20 16:40:22 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_str(char const *str, char ch)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ch == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && in_str(set, s1[start]))
		start++;
	while (end > start && in_str(set, s1[end - 1]))
		end--;
	trim = ft_substr(s1, start, end - start);
	if (!trim)
		return (NULL);
	return (trim);
}
