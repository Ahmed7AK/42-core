/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_handle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 07:12:29 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 16:09:49 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	format_handle(char ch, va_list *args)
{
	int	count;

	count = 0;
	if (ch == 'c')
		count += ft_print_c(va_arg(*args, int));
	else if (ch == 's')
		count += ft_print_s(va_arg(*args, char *));
	else if (ch == 'p')
		count += ft_print_ptr(va_arg(*args, void *));
	else if (ch == 'd' || ch == 'i')
		count += ft_print_int(va_arg(*args, int));
	else if (ch == 'u')
		count += ft_print_uint(va_arg(*args, unsigned int));
	else if (ch == 'x')
		count += ft_print_itox(va_arg(*args, unsigned int), 0);
	else if (ch == 'X')
		count += ft_print_itox(va_arg(*args, unsigned int), 1);
	else if (ch == '%')
		count += ft_print_c('%');
	return (count);
}
