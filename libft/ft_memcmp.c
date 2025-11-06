/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:42:41 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/02 17:26:35y akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    if (!s1 || !s2)
        return (0);

    unsigned char *ptr1;
    unsigned char *ptr2;
    size_t i;
    
    ptr1 = (unsigned char *)s1;
    ptr2 = (unsigned char *)s2;
    i = 0;
    while ((*ptr1|| *ptr2) && i < n)
    {
        if (*ptr1 > *ptr2)
            return ((int)*ptr1 - (int)*ptr2);
        if (*ptr1 < *ptr2)
            return ((int)*ptr1 - (int)*ptr2);
        i++;
        ptr1++;
        ptr2++;
    }
    return (0);
}
