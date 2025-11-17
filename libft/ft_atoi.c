/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:20:43 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/13 14:21:26 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overunder(int sum, int digit, int sign)
{
	if ((sum > 214748364
			|| (sum == 214748364 && digit > 7)) && sign == 1)
		return (0);
	else if ((sum > 214748364
			|| (sum == 214748364 && digit > 8)) && sign == -1)
		return (0);
	return (1);
}

static int	ft_isspace(char ch)
{
	if (ch == '\t' || ch == '\n' || ch == '\v'
		|| ch == '\f' || ch == '\r' || ch == 32)
		return (1);
	return (0);
}

static int	ft_sign(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	if (c == '+')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	sum;

	if (!str)
		return (0);
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_sign(str[i]) == -1 || ft_sign(str[i]) == 1)
	{
		sign = ft_sign(str[i]);
		i++;
	}
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_overunder(sum, str[i] - '0', sign) == 0)
			return (0);
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	return (sign * sum);
}
