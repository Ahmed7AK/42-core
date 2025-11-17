/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:09:38 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/15 14:54:33 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int				len;
	unsigned int	num;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		len++;
		num = (unsigned int)-n;
	}
	else
		num = (unsigned int)n;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static unsigned int	ft_set_sign(int n, char *num)
{
	unsigned int	nbr;

	if (n < 0)
	{
		num[0] = '-';
		nbr = (unsigned int)-n;
	}
	else
	{
		nbr = (unsigned int)n;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				len;
	unsigned int	nbr;

	len = ft_intlen(n);
	num = malloc((len + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
	{
		num[0] = '0';
		return (num);
	}
	nbr = ft_set_sign(n, num);
	len--;
	while (nbr > 0)
	{
		num[len] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	return (num);
}
