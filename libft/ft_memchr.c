/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 14:15:24 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/19 14:15:31 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*ptr;
	size_t			i;

	ch = (unsigned char) c;
	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (*ptr == ch)
			return ((void *) ptr);
		i++;
		ptr++;
	}
	return (NULL);
}
