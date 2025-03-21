/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:15:20 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/21 02:26:55 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @attention before calling this function, check the stack size equals 3
 * @brief orders a stack with 3 elements
 * @details sends max to the tail and swaps the first 2 numbers if necessary
 */
void	ft_sort_three(t_stack *stack)
{
	t_node	*max;

	max = ft_find_max(stack);
	while (!ft_stack_is_sorted(stack))
	{
		if (max == stack->tail)
			ft_sa(stack);
		else if (max == stack->head)
			ft_ra(stack);
		else
			ft_rra(stack);
	}
}

/**
 * @attention before calling this function, check the stack size equals 5
 * @brief orders a stack with 4 elements
 * @details pushes the min to b and calls ft_sort_three
 */
void	ft_sort_four(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min;

	min = ft_find_min(stack_a);
	ft_cheapest_rotate_a(stack_a, min);
	ft_pb(stack_a, stack_b);
	ft_assign_indexes(stack_a);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

/**
 * @attention before calling this function, check the stack size equals 5
 * @brief orders a stack with 5 elements
 * @details pushes the min to b and calls ft_sort_four
 */
void	ft_sort_five(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*min;

	min = ft_find_min(stack_a);
	ft_cheapest_rotate_a(stack_a, min);
	ft_pb(stack_a, stack_b);
	ft_assign_indexes(stack_a);
	ft_sort_four(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

/**
 * push to b until only 3 nodes remain in a
 * sort a
 * while b has nodes
 * 	reassign indexes to nodes
 * 	reassing target nodes
 * 	reassing costs
 * 	find the cheapest
 * 	put cheapest and its target on the top
 * 	push cheapest to a
 * at the end rotate stack to have the min on top
 */
void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;
	t_node	*first;

	while (ft_stack_size(stack_a) > 3)
		ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (stack_b->head)
	{
		ft_assign_indexes(stack_a);
		ft_assign_indexes(stack_b);
		ft_assign_target_nodes(stack_a, stack_b);
		ft_assign_costs(stack_a);
		ft_assign_costs(stack_b);
		cheapest = ft_find_cheapest(stack_b);
		ft_cheapest_rotate(stack_a, stack_b, cheapest);
		ft_pa(stack_a, stack_b);
	}
	first = ft_find_min(stack_a);
	ft_assign_indexes(stack_a);
	ft_cheapest_rotate_a(stack_a, first);
}
