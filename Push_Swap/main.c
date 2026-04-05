/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:22:14 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/05 12:33:48 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cleanup(t_list **stack_a, t_list **stack_b, char **args, int argc)
{
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(stack_a);
	free(stack_b);
	if (argc == 2)
		ft_free_split(args, count_words(args[0], ' '));
}

void	ft_init_stacks(t_list ***stack_a, t_list ***stack_b)
{
	*stack_a = malloc(sizeof(t_list *));
	*stack_b = malloc(sizeof(t_list *));
	if (!*stack_a || !*stack_b)
		exit(1);
	**stack_a = NULL;
	**stack_b = NULL;
}

int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	**args;

	if (!ft_check_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = &argv[1];
	ft_init_stacks(&stack_a, &stack_b);
	ft_fill_stack(stack_a, args);
	ft_normalize_index(stack_a);
	push_swap(stack_a, stack_b);
	ft_cleanup(stack_a, stack_b, args, argc);
}
