/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 02:16:25 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/05 15:53:40 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *num)
{
	int	i;
	int	tmp;
	int	sign;

	sign = 1;
	i = 0;
	tmp = 0;
	if (num[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		tmp = (tmp * 10) + (num[i] - '0');
		i++;
	}
	tmp *= sign;
	return (tmp);
}

static long	ft_atol(char *num)
{
	int		i;
	long	tmp;
	int		sign;

	sign = 1;
	i = 0;
	tmp = 0;
	if (!num)
		return (0);
	if (num[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (num[i] >= '0' && num[i] <= '9')
	{
		tmp = (tmp * 10) + (num[i] - '0');
		i++;
	}
	tmp *= sign;
	return (tmp);
}

static int	ft_check_dup(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atol(args[i]) == ft_atol(args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int		i;
	long	tmp;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i] >= '0' && num[i] <= '9')
		i++;
	if (num[i] == '\0')
	{
		tmp = ft_atol(num);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (0);
		return (1);
	}
	return (0);
}

int	ft_check_args(int argc, char *argv[])
{
	int		i;
	char	**args;

	if (argc < 2)
		return (0);
	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	if (ft_check_dup(args))
		return (0);
	while (args[i])
	{
		if (!ft_isnum(args[i]))
			return (0);
		i++;
	}
	if (argc == 2)
		ft_free_split(args, i);
	return (1);
}
