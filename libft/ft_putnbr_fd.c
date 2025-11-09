/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:42:34 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/08 17:58:43 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char    *num;
    int i;
    
    num = ft_itoa(n);
    i = 0; 
    while (num[i])
    {
        write(fd, &num[i], 1);
        i++;
    }
    free(num);
}