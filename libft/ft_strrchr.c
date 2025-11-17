/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:01:14 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/13 10:26:18 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	char			*ptr;
	int				i;

	if (!s)
		return (NULL);
	ch = (unsigned char) c;
	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			ptr = (char *) &s[i];
		i++;
	}
	if (s[i] == ch)
		ptr = (char *) &s[i];
	return (ptr);
}
