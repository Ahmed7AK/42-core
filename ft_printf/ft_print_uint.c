/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:24:02 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 15:51:14 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_uint(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
		count += ft_print_uint(nbr / 10);
	count += ft_print_c((nbr % 10) + '0');
	if (count < 0)
		return (-1);
	return (count);
}
