/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:40:57 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/03 06:51:55 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*m1;
	t_list	*m2;
	t_list	*l1;
	t_list	*l2;

	m1 = *stack_a;
	while (m1->next->next != NULL)
		m1 = m1->next;
	l1 = ft_lstlast(*stack_a);
	m1->next = NULL;
	ft_lstadd_front(stack_a, l1);
	m2 = *stack_b;
	while (m2->next->next != NULL)
		m2 = m2->next;
	l2 = ft_lstlast(*stack_b);
	m2->next = NULL;
	ft_lstadd_front(stack_b, l2);
	write(1, "rrr\n", 4);
}
