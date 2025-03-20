/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 23:45:36 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/20 23:48:04 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node				*ft_find_min(t_stack *stack);
t_node				*ft_find_max(t_stack *stack);
t_node				*ft_find_cheapest(t_stack *stack);
static unsigned int	ft_get_total_cost(t_node *node);

t_node	*ft_find_min(t_stack *stack)
{
	t_node	*node;
	t_node	*min;

	node = stack->head;
	min = node;
	while (node)
	{
		if (node->value < min->value)
			min = node;
		node = node->next;
	}
	return (min);
}

t_node	*ft_find_max(t_stack *stack)
{
	t_node	*node;
	t_node	*max;

	node = stack->head;
	max = node;
	while (node)
	{
		if (node->value > max->value)
			max = node;
		node = node->next;
	}
	return (max);
}

t_node	*ft_find_cheapest(t_stack *stack)
{
	t_node			*current;
	t_node			*cheapest;

	current = stack->head;
	cheapest = stack->head;
	while (current)
	{
		if (ft_get_total_cost(current) < ft_get_total_cost(cheapest))
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

static unsigned int	ft_get_total_cost(t_node *node)
{
	return (node->cost + node->target->cost);
}
