/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:31:15 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/10 11:49:51 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list  *next;

    while (*lst)
    {
        next = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = next;
    }
    free(*lst);
    *lst = NULL;
}