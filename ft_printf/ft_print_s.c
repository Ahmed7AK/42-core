/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 07:16:26 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 16:12:10 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_s(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (str[count])
	{
		if (ft_print_c(str[count]) == -1)
			return (-1);
		count++;
	}
	return (count);
}
