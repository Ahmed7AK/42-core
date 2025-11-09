/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 13:52:28 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/08 15:49:51 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int len;
    char *result;
    int i;

    len = ft_strlen(s);
    result = malloc((len + 1) * sizeof(char));
    if (!result || !s)
        return (NULL);

    i = 0;
    while (s[i])
    {
        result[i] = f(i, s[i]);
        i++;
    }
    result[i] = '\0';
    return (result);
}