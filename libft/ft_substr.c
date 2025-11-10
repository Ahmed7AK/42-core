/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:44:01 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/10 10:43:34 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  i;
    unsigned int    slen;

    sub = malloc(len + 1);
    if (!s || !sub)
        return (NULL);

    i = 0;
    slen = ft_strlen(s);
    while (s[i] != '\0' && i < len && !(start > slen))
    {
        sub[i] = s[start + i];    
        i++;
    }
    sub[i] = '\0';
    return (sub);
}