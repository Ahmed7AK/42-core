/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:59:42 by akheiral          #+#    #+#             */
/*   Updated: 2025/10/28 16:28:22 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t		i;
	
	ptr = (unsigned char*)b;
	ch = (unsigned char)c;
	i = 0;
	while (i <= len)
	{
		ptr[i] = ch;
		i++;
	}
	return(b);
}

