/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akheiral <akheiral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:11:27 by akheiral          #+#    #+#             */
/*   Updated: 2026/04/06 14:10:56 by akheiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H	

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}	t_list;

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		count_words(char const *str, char c);
char	**ft_split(char const *s, char c);
void	ft_free_split(char **strs, int count);

int		ft_atoi(char *num);
int		ft_check_args(int argc, char *argv[]);

t_list	*ft_newnode(int value);
void	ft_lstadd_front(t_list **lst, t_list *node);
void	ft_lstdelone(t_list *node);
void	ft_lstclear(t_list **lst);
int		ft_lstsize(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_sa(t_list **stack_a);
void	ft_sb(t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

int		ft_find_lowest(t_list **stack);
int		ft_stack_len(t_list **stack);
void	ft_normalize_index(t_list **stack);
void	ft_fill_stack(t_list **stack, char **args);
void	ft_sort_three(t_list **stack);

void	chunk_sort(t_list **stack_a, t_list **stack_b);

int		push_swap(t_list **stack_a, t_list **stack_b);

#endif