/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:24:22 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/26 00:02:30 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
// ##### includes #####
# include "libft/libft.h"
// utils
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

// ##### structs #####
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	unsigned int	index;
	struct s_node	*target;
	unsigned int	cost;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

// ##### movs (pa, ra, ...) #####
// push
void			ft_pa(t_stack *stack_a, t_stack *stack_b);
void			ft_pb(t_stack *stack_a, t_stack *stack_b);
// swap
void			ft_sa(t_stack *stack_a);
void			ft_sb(t_stack *stack_b);
void			ft_ss(t_stack *stack_a, t_stack *stack_b);
// rotate
void			ft_ra(t_stack *stack_a);
void			ft_rb(t_stack *stack_b);
void			ft_rr(t_stack *stack_a, t_stack *stack_b);
// reverse rotate
void			ft_rra(t_stack *stack_a);
void			ft_rrb(t_stack *stack_b);
void			ft_rrr(t_stack *stack_a, t_stack *stack_b);

// ##### sorts #####
void			ft_sort_three(t_stack *stack);
void			ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void			ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void			ft_sort(t_stack *stack_a, t_stack *stack_b);

// ##### utils #####
void			ft_exit(void);
void			ft_free_stack_and_exit(t_stack *stack);
// stack utils
void			ft_delete_stack(t_stack **stack);
int				ft_stack_is_sorted(t_stack *stack);
t_node			*ft_find_min(t_stack *stack);
t_node			*ft_find_max(t_stack *stack);
unsigned int	ft_stack_size(t_stack *stack);
void			ft_assign_indexes(t_stack *stack);
void			ft_assign_target_nodes(t_stack *stack_a, t_stack *stack_b);
void			ft_assign_costs(t_stack *stack);
t_node			*ft_find_cheapest(t_stack *stack);
int				ft_add_number_to_stack(char *str, t_stack *stack);

// rotate utils
void			ft_cheapest_rotate_a(t_stack *stack, t_node *node);
void			ft_cheapest_rotate(t_stack *stack_a, t_stack *stack_b,
					t_node *cheapest);

#endif
