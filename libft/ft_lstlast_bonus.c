/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:48:32 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/09 13:04:31 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstlast(t_list *lst)
{
    t_list *tmp;

    if (!lst)
        return (NULL);
    
    tmp = lst;
    while (tmp->next)
        tmp = tmp->next;

    return (tmp);
}