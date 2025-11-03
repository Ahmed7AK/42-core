/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:18:28 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/01 19:19:29 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	if (!dst || !src)
		return (0);

	unsigned char 	*dst_ptr;
	unsigned char	*src_ptr;
	size_t		i;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}
