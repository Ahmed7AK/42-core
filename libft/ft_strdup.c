/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:26:31 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/03 12:34:56 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char    *ft_strdup(const char *s1)
{
    if (!s1)
        return (NULL);
    
    int len;
    char    *dup;
    int i;
    
    len = 0;
    while (s1[len])
        len++;

    dup = malloc(len + 1);
    if (!dup)
        return (NULL);
    
    i = 0;
    while (s1[i])
    {
        dup[i] = s1[i];
        i++;
    }
    dup[i] = '\0';
    
    return (dup);
}