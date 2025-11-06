/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:57:42 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/03 13:51:48 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    if (!s)
		return (0);

    unsigned char *ptr;
    unsigned char ch;
    size_t i;

    ptr = (unsigned char*)s;
    ch = (unsigned char)c;
    i = 0;
    while (*ptr++ && i < n)
    {
        if (*ptr == ch)
            return ((void *)ptr);
        
        i++;
    }
    
    return (NULL);
}
