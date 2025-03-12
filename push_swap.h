/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:24:22 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/12 16:46:44 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
// ##### includes #####
# include <stdio.h> // TODO delete
// utils
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

// ##### structs #####
typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				value;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

// ##### movs (pa, ra, ...) #####
// push
void	ft_pa(t_stack *stack_a, t_stack *stack_b);
void	ft_pb(t_stack *stack_a, t_stack *stack_b);
// swap
void	ft_sa(t_stack *stack_a);
void	ft_sb(t_stack *stack_b);
void	ft_ss(t_stack *stack_a, t_stack *stack_b);
// rotate
void	ft_ra(t_stack *stack_a);
void	ft_rb(t_stack *stack_b);
void	ft_rr(t_stack *stack_a, t_stack *stack_b);
// reverse rotate
void	ft_rra(t_stack *stack_a);
void	ft_rrb(t_stack *stack_b);
void	ft_rrr(t_stack *stack_a, t_stack *stack_b);

// ##### sorts #####
void	ft_short_three(t_stack *stack);

// ##### utils #####
void	ft_exit(void);
void	ft_free_and_exit(t_stack *stack);
// stack utils
int		ft_value_exists(t_stack *stack, int value);
void	ft_new_node(t_stack *stack, int value);
void	ft_print_stack(t_stack *stack, char c);
void	ft_delete_stack(t_stack **stack);
int		ft_stack_is_sorted(t_stack *stack);
t_node	*ft_find_min(t_stack *stack);
t_node	*ft_find_max(t_stack *stack);

// libft utils
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str, t_stack *stack);
size_t	ft_strlen(const char *s);

#endif
