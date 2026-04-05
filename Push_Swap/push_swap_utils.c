/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:15:42 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/05 11:27:21 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_lowest(t_list **stack)
{
	int		lowest;
	t_list	*tmp;

	tmp = *stack;
	lowest = INT_MAX;
	while (tmp != NULL)
	{
		if (tmp->value < lowest && tmp->index == -1)
			lowest = tmp->value;
		tmp = tmp->next;
	}
	return (lowest);
}

int	ft_stack_len(t_list **stack)
{
	int		len;
	t_list	*tmp;

	if (!stack || !(*stack))
		return (0);
	len = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void	ft_normalize_index(t_list **stack)
{
	int		i;
	int		len;
	int		lowest;
	t_list	*tmp;

	len = ft_stack_len(stack);
	i = 0;
	while (i < len)
	{
		tmp = *stack;
		lowest = ft_find_lowest(stack);
		while (tmp != NULL)
		{
			if (tmp->value == lowest)
				tmp->index = i;
			tmp = tmp->next;
		}
		i++;
	}
}

void	ft_fill_stack(t_list **stack, char **args)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (args[i])
	{
		tmp = ft_newnode(ft_atoi(args[i]));
		if (!tmp)
		{
			ft_lstclear(stack);
			return ;
		}
		ft_lstadd_back(stack, tmp);
		i++;
	}
}
