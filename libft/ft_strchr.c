/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 09:59:21 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/02 10:00:54 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	
	unsigned char ch;
	char	*ptr;
	
	ch = c;
	ptr = s;
	while (*s)
	{
		if (*s == ch)
			return (ptr);
		*s++;
		ptr = s;
	}
	if (*s == ch)
		return (ptr);
	return (NULL);
}