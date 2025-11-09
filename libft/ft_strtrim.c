/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:37:07 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/07 20:06:09 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  int in_str(char const *str, char ch)
{
    int i;
    
    i = 0;
    while (str[i] != '\0')
    {
        if (ch == str[i])
            return (1);
        i++;
    }
    return (0);
}

static  int find_len(char const *str, char const *filter)
{
    int len;
    int i;

    len = 0;
    i = 0;    
    while (str[i] != '\0')
    {
        if (!in_str(filter, str[i]))
            len++;
        i++;
    }

    return (len);
}

char    *ft_strtrim(char const *s1, char const *set)
{
    int len;
    char    *trim;
    int i;
    int j;
    
    len = find_len(s1, set);
    trim = malloc(len + 1);
    if (!trim || !s1 || !set)
        return (NULL);
    
    i = 0;
    j = 0;
    while (s1[i] != '\0')
    {
        if (!in_str(set, s1[i]))
        {
            trim[j] = s1[i];
            j++;
        }
        i++;
    }
    trim[j] = '\0'; 
    
    return (trim);
}