/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:00 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/06 14:19:49 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @return 0 if value doesn't exist, 1 if it alredy exists
 */
int	ft_value_exists(t_stack *stack, int value)
{
	t_node	*node;

	if (!stack)
		return (0);
	node = stack->head;
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	
	return (0);
}

void ft_new_node(t_stack *stack, int value)
{
	t_node *new_node;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
	
	if (!stack->head)
	{
		new_node->prev = NULL;
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{	
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
}
