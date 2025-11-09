/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:59:54 by akheiral          #+#    #+#             */
/*   Updated: 2025/11/09 18:43:21 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list  *newlst;
    t_list  *node;
    if (!lst || !f || !del)
        return (NULL);

    newlst = ft_lstnew(f(lst->content));
    if (!newlst)
        return (NULL);

    lst = lst->next;
    while (lst)
    {
        node = ft_lstnew(f(lst->content));
        if (!node)
        {
            ft_lstclear(&newlst, del);
            return (NULL);
        }   
        ft_lstadd_back(&newlst, node);
        lst = lst->next;
    }
    return (newlst);
}
