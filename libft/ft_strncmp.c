/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:37:05 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/05 12:48:27 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    if (!s1 || !s2)
        return (0);

    size_t i;

    i = 0;
    while (*s1 && *s2 && i < n)
    {
        if (*s1 > *s2)
            return ((int)*s1 - (int)*s2);
        if (*s1 < *s2)
            return ((int)*s1 - (int)*s2);
        i++;
        s1++;
        s2++;
    }
    return (0);
}