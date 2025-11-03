/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:37:59 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/03 10:17:31 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{

    if (!haystack || !needle)
        return (NULL);
    
    if (*needle == '\0')
        return ((char *)haystack);

    char *ptr;
    size_t i;

    ptr = NULL; 
    i = 0;
    while (*haystack && i < len-1)
    {
       if (*haystack == *needle)
       {
        ptr = haystack;
        while (*needle == *haystack && i < len-1)
        {
            if (*(needle + 1) == '\0')
                return (ptr);
            else
                ptr = NULL;
            *needle++;
            *haystack++;
            i++;
        }
       } 
       i++;
        *haystack++;
    }
    return (ptr);
}