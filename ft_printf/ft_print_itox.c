/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_itox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:34:58 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 15:52:04 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_itox(unsigned int nbr, int c)
{
	char	*hexu;
	char	*hexl;
	char	ch;
	int		count;

	hexu = "0123456789ABCDEF";
	hexl = "0123456789abcdef";
	count = 0;
	if (nbr >= 16)
		count += ft_print_itox(nbr / 16, c);
	if (c == 1)
		ch = hexu[nbr % 16];
	else
		ch = hexl[nbr % 16];
	count += ft_print_c(ch);
	if (count < 0)
		return (-1);
	return (count);
}
