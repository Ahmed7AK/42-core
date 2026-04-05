/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 05:40:24 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/04 12:57:01 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **stack_a)
{
	int	tmp_value;
	int	tmp_index;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	tmp_value = (*stack_a)->value;
	tmp_index = (*stack_a)->index;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->value = tmp_value;
	(*stack_a)->next->index = tmp_index;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	int	tmp_value;
	int	tmp_index;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	tmp_value = (*stack_b)->value;
	tmp_index = (*stack_b)->index;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->value = tmp_value;
	(*stack_b)->next->index = tmp_index;
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	int	tmp_value;
	int	tmp_index;

	if (*stack_a == NULL || *stack_b == NULL)
		return ;
	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	tmp_value = (*stack_a)->value;
	tmp_index = (*stack_a)->index;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->index = (*stack_a)->next->index;
	(*stack_a)->next->value = tmp_value;
	(*stack_a)->next->index = tmp_index;
	tmp_value = (*stack_b)->value;
	tmp_index = (*stack_b)->index;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->index = (*stack_b)->next->index;
	(*stack_b)->next->value = tmp_value;
	(*stack_b)->next->index = tmp_index;
	write(1, "ss\n", 3);
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b == NULL || !(*stack_b))
		return ;
	tmp = (*stack_b)->next;
	ft_lstadd_front(stack_a, *stack_b);
	*stack_b = tmp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_a == NULL || !(*stack_a))
		return ;
	tmp = (*stack_a)->next;
	ft_lstadd_front(stack_b, *stack_a);
	*stack_a = tmp;
	write(1, "pb\n", 3);
}
