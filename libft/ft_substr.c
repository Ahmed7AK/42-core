/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:44:01 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/06 09:55:47 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *sub;
    size_t  i;

    sub = malloc(len + 1);
    if (!s || !sub)
        return (NULL);

    i = 0;
    while (s[i] != '\0' && i < len)
    {
        sub[i] = s[start + i];    
        i++;
    }
    sub[i] = '\0';
    return (sub);
}