/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:52:06 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/06 14:51:12 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	int		i;
	int		len;
	t_list	*tmp;

	len = ft_stack_len(stack) - 1;
	i = 0;
	tmp = *stack;
	while (i < len)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}

void	ft_simple_sort(t_list **stack_a, t_list **stack_b, int len_a)
{
	int	n;

	n = len_a - 3;
	while (len_a != 3)
	{
		if ((*stack_a)->index < n)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		len_a = ft_stack_len(stack_a);
	}
	if (is_sorted(stack_b))
		ft_sb(stack_b);
	ft_sort_three(stack_a);
	n = ft_stack_len(stack_b);
	while (n-- > 0)
		ft_pa(stack_a, stack_b);
}

static int	radix_bits(int len_a)
{
	int	bits;

	bits = 0;
	while (len_a > 0)
	{
		bits++;
		len_a /= 2;
	}
	return (bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int len_a)
{
	int	i;
	int	size;
	int	bits_needed;
	int	bit;

	bits_needed = radix_bits(len_a);
	bit = 0;
	while (bit < bits_needed)
	{
		i = 0;
		while (i < len_a)
		{
			if (((*stack_a)->index >> bit) & 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
			i++;
		}
		size = ft_stack_len(stack_b);
		while (size-- > 0)
			ft_pa(stack_a, stack_b);
		bit++;
	}
}

int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	len_a;

	len_a = ft_stack_len(stack_a);
	if (len_a == 1 || is_sorted(stack_a))
		return (1);
	else if (len_a == 2)
		ft_sa(stack_a);
	else if (len_a <= 5)
		ft_simple_sort(stack_a, stack_b, len_a);
	else if (len_a <= 20)
		radix_sort(stack_a, stack_b, len_a);
	else if (len_a > 20)
		chunk_sort(stack_a, stack_b);
	else
		return (0);
	return (1);
}
