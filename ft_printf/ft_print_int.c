/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 13:27:02 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 16:12:57 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_int(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += ft_print_s("-2147483648");
		return (count);
	}
	if (nbr < 0)
	{
		count += ft_print_c('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		count += ft_print_int(nbr / 10);
	count += ft_print_c((nbr % 10) + '0');
	return (count);
}
