/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:21:40 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 15:47:11 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_print_hex(unsigned long nbr)
{
	char	*hex;
	char	ch;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (nbr >= 16)
		count += ft_print_hex(nbr / 16);
	ch = hex[nbr % 16];
	count += ft_print_c(ch);
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				count;

	count = 0;
	addr = (unsigned long)ptr;
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_print_hex(addr);
	if (count < -1)
		return (-1);
	return (count);
}
