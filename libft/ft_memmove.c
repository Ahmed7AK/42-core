/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:25:23 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/01 19:25:25 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return;

	unsigned char 	*dst_ptr;
	unsigned char	*src_ptr;
	size_t		i;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	dst_ptr[i] = '\0';
	return (dst);
}
