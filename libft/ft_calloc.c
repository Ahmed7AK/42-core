/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:58:43 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/03 12:28:47 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void    *ft_calloc(size_t count, size_t size)
{
    void    *mem;
    unsigned char   *ptr;
    size_t i;
    
    mem = malloc(count * size);
    ptr = (unsigned char *)mem;
    if (!mem)
        return (NULL);

    i = 0;
    while (i < count * size)
    {
        *ptr++ = 0;
        i++;
    }
    return (mem);
}