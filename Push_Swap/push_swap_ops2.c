/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 06:40:12 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/03 06:43:31 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a)
{
	t_list	*start;
	t_list	*middle;

	middle = (*stack_a)->next;
	start = *stack_a;
	start->next = NULL;
	ft_lstadd_back(&middle, start);
	*stack_a = middle;
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*start;
	t_list	*middle;

	middle = (*stack_b)->next;
	start = *stack_b;
	start->next = NULL;
	ft_lstadd_back(&middle, start);
	*stack_b = middle;
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*s1;
	t_list	*s2;
	t_list	*m1;
	t_list	*m2;

	m1 = (*stack_a)->next;
	s1 = *stack_a;
	s1->next = NULL;
	ft_lstadd_back(&m1, s1);
	*stack_a = m1;
	m2 = (*stack_b)->next;
	s2 = *stack_b;
	s2->next = NULL;
	ft_lstadd_back(&m2, s2);
	*stack_b = m2;
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*middle;
	t_list	*last;

	middle = *stack_a;
	while (middle->next->next != NULL)
		middle = middle->next;
	last = ft_lstlast(*stack_a);
	middle->next = NULL;
	ft_lstadd_front(stack_a, last);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*middle;
	t_list	*last;

	middle = *stack_b;
	while (middle->next->next != NULL)
		middle = middle->next;
	last = ft_lstlast(*stack_b);
	middle->next = NULL;
	ft_lstadd_front(stack_b, last);
	write(1, "rrb\n", 4);
}
