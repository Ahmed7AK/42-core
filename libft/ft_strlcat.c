/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:34:45 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/20 12:45:59 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	copylen;

	srclen = ft_strlen(src);
	if (!dst && dstsize == 0 && src)
		return (srclen);
	dstlen = 0;
	while (dst[dstlen] != '\0' && dstlen < dstsize)
		dstlen++;
	if (dstlen == dstsize)
		return (dstsize + srclen);
	copylen = dstsize - dstlen - 1;
	if (srclen < copylen)
		copylen = srclen;
	ft_memcpy(dst + dstlen, src, copylen);
	dst[dstlen + copylen] = '\0';
	return (dstlen + srclen);
}
