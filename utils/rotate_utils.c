/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:18:22 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/25 23:45:41 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_below_mid(t_node *node, unsigned int size);
static int	ft_node_is_on_top(t_node *node, t_stack *stack);

void	ft_cheapest_rotate_a(t_stack *stack, t_node *node)
{
	unsigned int	size;
	unsigned int	index;

	size = ft_stack_size(stack);
	index = node->index;
	if (ft_below_mid(node, size))
	{
		while (index-- != 0)
			ft_ra(stack);
	}
	else
	{
		while (index++ != size)
			ft_rra(stack);
	}
}

void	ft_cheapest_rotate_b(t_stack *stack, t_node *node)
{
	unsigned int	size;
	unsigned int	index;

	size = ft_stack_size(stack);
	index = node->index;
	if (ft_below_mid(node, size))
	{
		while (index-- != 0)
			ft_rb(stack);
	}
	else
	{
		while (index++ != size)
			ft_rrb(stack);
	}
}

void	ft_cheapest_rotate(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
	unsigned int	size_a;
	unsigned int	size_b;

	size_a = ft_stack_size(stack_a);
	size_b = ft_stack_size(stack_b);
	if (ft_below_mid(cheapest, size_b)
		&& ft_below_mid(cheapest->target, size_a))
	{
		while (!ft_node_is_on_top(cheapest->target, stack_a)
			&& !ft_node_is_on_top(cheapest, stack_b))
			ft_rr(stack_a, stack_b);
	}
	else if (!ft_below_mid(cheapest, size_b)
		&& !ft_below_mid(cheapest->target, size_a))
	{
		while (!ft_node_is_on_top(cheapest->target, stack_a)
			&& !ft_node_is_on_top(cheapest, stack_b))
			ft_rrr(stack_a, stack_b);
	}
	ft_assign_indexes(stack_a);
	ft_assign_indexes(stack_b);
	if (!ft_node_is_on_top(cheapest->target, stack_a))
		ft_cheapest_rotate_a(stack_a, cheapest->target);
	if (!ft_node_is_on_top(cheapest, stack_b))
		ft_cheapest_rotate_b(stack_b, cheapest);
}

static int	ft_below_mid(t_node *node, unsigned int size)
{
	return (node->index <= size / 2);
}

static int	ft_node_is_on_top(t_node *node, t_stack *stack)
{
	return (node == stack->head);
}
