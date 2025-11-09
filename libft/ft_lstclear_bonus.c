/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:31:15 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/09 16:16:34 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *current;
    t_list  *next;

    current = *lst;
    while (current)
    {
        next = current->next;
        ft_lstdelone(current, del);
        current = next;
    }
    free(current);
    current = NULL;
}