/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:20:43 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/03 11:26:30 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(const char *str)
{
    if (!str)
        return (0);
    
    int sign;
    int i;
    int sum;

    sign = 1;
    i = 0;
    if (str[i] == '-')
    {
        sign *= -1;
        i++;
    }
    else if (str[i] == '+')
    {
        sign *= 1;
        i++;
    }
    
    sum = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        sum = sum * 10 + str[i] - '0';
        i++;
    }
    
    return (sign * sum);
} 
