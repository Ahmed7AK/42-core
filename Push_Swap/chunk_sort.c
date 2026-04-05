/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 13:31:57 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/05 11:21:26 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_biggest_pos(t_list **stack)
{
	t_list	*tmp;
	int		i;
	int		biggest_value;
	int		biggest_pos;
	int		len;

	len = ft_stack_len(stack);
	i = 0;
	biggest_value = -1;
	biggest_pos = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->index >= biggest_value)
		{
			biggest_value = tmp->index;
			biggest_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (biggest_pos);
}

void	ft_chunk_push(t_list **stack_a, t_list **stack_b, int len_a)
{
	int	chunk_num;
	int	n;
	int	i;

	chunk_num = 40;
	if (len_a <= 100)
		chunk_num = 20;
	n = 0;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
			i++;
		}
		else if ((*stack_a)->index <= i + chunk_num)
		{
			ft_pb(stack_a, stack_b);
			i++;
		}
		else
			ft_ra(stack_a);
	}
}

void	ft_chunk_pull(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	len_b;

	while (*stack_b)
	{
		len_b = ft_stack_len(stack_b);
		pos = ft_biggest_pos(stack_b);
		if (pos <= len_b / 2)
		{
			while (pos-- > 0)
				ft_rb(stack_b);
		}
		else
		{
			while (pos++ < len_b)
				ft_rrb(stack_b);
		}
		ft_pa(stack_a, stack_b);
	}
}

int	ft_find_zero(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->index == 0)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	chunk_sort(t_list **stack_a, t_list **stack_b)
{
	int	len_a;
	int	pos;

	len_a = ft_stack_len(stack_a);
	ft_chunk_push(stack_a, stack_b, len_a);
	ft_chunk_pull(stack_a, stack_b);
	pos = ft_find_zero(stack_a);
	if (pos <= len_a / 2)
	{
		while (pos-- > 0)
			ft_ra(stack_a);
	}
	else
	{
		while (pos++ < len_a)
			ft_rra(stack_a);
	}
}
