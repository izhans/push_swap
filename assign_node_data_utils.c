/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:31:09 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/20 23:38:19 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_assign_indexes(t_stack *stack);
void				ft_assign_target_nodes(t_stack *stack_a, t_stack *stack_b);
static t_node		*ft_find_target_node(t_stack *stack, t_node *node);
void				ft_assign_costs(t_stack *stack);
static unsigned int	ft_calc_node_cost(t_node *node, unsigned int stack_size);

void	ft_assign_indexes(t_stack *stack)
{
	unsigned int	index;
	t_node			*current;

	index = 0;
	current = stack->head; // ! segfaults if !stack
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

void	ft_assign_target_nodes(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_b->head;
	while (current)
	{
		current->target = ft_find_target_node(stack_a, current);
		current = current->next;
	}
}

static t_node	*ft_find_target_node(t_stack *stack, t_node *node)
{
	t_node	*current;
	t_node	*target;

	current = stack->head;
	target = ft_find_min(stack);
	while (current)
	{
		if (current->value > node->value
			&& (target->value < node->value || current->value < target->value))
			target = current;
		current = current->next;
	}
	return (target);
}

void	ft_assign_costs(t_stack *stack)
{
	unsigned int	stack_size;
	t_node			*current;

	stack_size = ft_stack_size(stack);
	current = stack->head;
	while (current)
	{
		current->cost = ft_calc_node_cost(current, stack_size);
		current = current->next;
	}
}

static unsigned int	ft_calc_node_cost(t_node *node, unsigned int stack_size)
{
	if (node->index <= stack_size / 2)
		return (node->index);
	return (stack_size - node->index);
}
