/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:26:48 by akheiral          #+#    #+#             */
/*   Updated: 2025/12/08 12:07:00 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	format_handle(char ch, va_list *args);
int	ft_print_c(char ch);
int	ft_print_s(char *str);
int	ft_print_ptr(void *ptr);
int	ft_print_int(int nbr);
int	ft_print_uint(unsigned int nbr);
int	ft_print_itox(unsigned int nbr, int c);
int	ft_printf(const char *format, ...);

#endif