/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:54:38 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/07 20:05:19 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int count_words(char const *str, char c)
{
    int len;

    len = 0;
    while (*str)
    {
        if (c == *str)
            len++;
        str++;
    }
    return (len + 1);
}


char    **ft_split(char const *s, char c)
{
    int words;
    char **strs;
    int i;
    int start;
    int j;
    
    words = count_words(s, c);
    strs = malloc((words + 1) * sizeof(char *));
    if (!strs && !s)
        return (NULL);
    
    i = 0;
    start = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] && s[i] == c)
            i++;
        start = i;
        while (s[i] && s[i] != c)
            i++;
        if (i > start)
            strs[j++] = ft_substr(s, start, i - start);
    }
    strs[j] = NULL;

    return (strs);
}
