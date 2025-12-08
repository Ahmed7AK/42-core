/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:07:22 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 16:13:37 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += format_handle(format[i + 1], &args);
			i++;
		}
		else
			count += ft_print_c(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
