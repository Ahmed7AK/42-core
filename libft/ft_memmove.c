/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:25:23 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/05 14:09:30 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (NULL);

	unsigned char 	*dst_ptr;
	unsigned char	*src_ptr;
	size_t		i;

	if (len == 0 || dst == src)
		return (dst);

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	i = 0;
	
	if (dst_ptr < src_ptr)
	{
		while (i < len)
		{
			dst_ptr[i] = src_ptr[i];
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			len--;
			dst_ptr[len] = src_ptr[len];
		}
	}
	return (dst);
}
