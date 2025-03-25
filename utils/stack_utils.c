/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:00 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/26 00:08:45 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void			ft_delete_stack(t_stack **stack);
int				ft_stack_is_sorted(t_stack *stack);
unsigned int	ft_stack_size(t_stack *stack);

void	ft_delete_stack(t_stack **stack)
{
	t_node	*node;
	t_node	*next;

	node = (*stack)->head;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(*stack);
	*stack = NULL;
}

/**
 * the stack is ordered if the tail is reached
 */
int	ft_stack_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node->next && node->value < node->next->value)
		node = node->next;
	return (node->next == NULL);
}

unsigned int	ft_stack_size(t_stack *stack)
{
	unsigned int	size;
	t_node			*current;

	size = 0;
	if (!stack)
		return (0);
	current = stack->head;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}
