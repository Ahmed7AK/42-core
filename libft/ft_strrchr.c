/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:01:14 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/19 09:51:40 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	int				i;

	ptr = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			ptr = (char *) &s[i];
		i++;
	}
	if (s[i] == c)
		ptr = (char *) &s[i];
	return (ptr);
}
