/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:59:13 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/06 10:17:53 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return (NULL);

    size_t  len1;
    size_t  len2;
    char    *str;
    size_t  i;
    size_t  j;
    
    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc(len1 + len2 + 1);
    i = 0;
    while (i < len1)
    {
        str[i] = s1[i];
        i++;   
    }
    j = 0;
    while (j < len2)
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}