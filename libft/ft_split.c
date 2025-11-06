/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:54:38 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/06 15:07:28 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int count_words(char const *str, char c)
{
    int len;

    len = 0;
    while (*str)
    {
        if (c == *str)
            len++;
        str++;
    }
    return (len);
}

char    **ft_split(char const *s, char c)
{
    int word_count;
    char **strs;
    int i;
    int j;

    word_count = count_words(s, c);
    strs = malloc((word_count + 1) * sizeof(char *));

    i = 0;
    j = 0;
    while (s[i])
    {
        while (s[i] != c)
        {
            strs[j] = s[i];
            j++;
        }
        i++;
    }
    
}