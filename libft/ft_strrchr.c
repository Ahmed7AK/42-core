/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:01:14 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/02 10:34:23 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
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
			ptr = s;
		*s++;
	}
    
    if (*s == ch)
        return ("\0");

    if (ptr)
        return (ptr);

    return (NULL);
}
