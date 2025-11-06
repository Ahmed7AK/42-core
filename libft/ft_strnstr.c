/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 17:37:59 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/05 13:21:30 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{

    if (!haystack || !needle)
        return (NULL);
    
    if (*needle == '\0')
        return ((char *)haystack);

    size_t i;
    size_t j;
    
    i = 0;
    while (haystack[i] && i < len)
    {
        j = 0;
        while (needle[j] == haystack[i + j] && i + j < len)
        {
            if (needle[j + 1] == '\0')
                return ((char *)(haystack + i));
            j++;
        }
        i++;
    }    
    return (NULL);
}