/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:09:38 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/10 10:56:45 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static  int ft_intlen(int n)
{
    int len;

    len = 0;
    if (n < 0)
    {
        n *= -1;
        len++;
    }
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

static void ft_reverse(char *str)
{
    int i;
    int len;
    char    buff;
    
    len = ft_strlen(str);
    i = 0;
    while (i < len)
    {
        buff = str[i];
        str[i] = str[len - 1];
        str[len - 1] = buff;
        i++;
        len--;
    }
}

char    *ft_itoa(int n)
{
    int sign;
    int len;
    char *num;
    int i; 
    
    sign = 1;
    if (n < 0)
    {
        sign = -1;
        n *= -1;
    }
   
    len = ft_intlen(n) + 1;
    num = malloc(len * sizeof(char));
    i = 0;
    while (n > 0)
    {
        num[i] = n % 10 + '0';
        n /= 10;
        i++;
    }
    if (sign < 0)
        num[i++] = '-';
    
    num[i] = '\0';
    ft_reverse(num);
    return (num);
}