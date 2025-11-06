/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:01:14 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/05 12:30:22 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	
	unsigned char ch;
	char	*ptr;
	
	ch = c;
	ptr = (char *)s;
	while (*s)
	{
		if (*s == ch)
			ptr = (char *)s;
		s++;
	}
    
    if (*s == ch)
        return ((char *)s);

    if (*ptr == ch)
        return (ptr);

    return (NULL);
}