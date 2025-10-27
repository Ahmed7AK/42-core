/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 20:39:22 by akheiral          #+#    #+#             */
/*   Updated: 2025/10/25 20:39:25 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*dstp;
	unsigned char	*srcp;
	char			*old;
	int				i;

	dstp = (unsigned char *)dst;
	srcp = (unsigned char *)src;
	old = dst;
	i = 0;
	while (i < n)
	{
		dstp[i] = srcp[i];
		i++;
	}
	dstp[i] = '\0';
	return (old);
}
