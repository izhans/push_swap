/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:00 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/12 17:26:55 by isastre-         ###   ########.fr       */
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

void ft_print_stack(t_stack *stack, char c)
{
	t_node *current;

	printf("stack_%c\n", c);
	if (!stack)
	{
		printf("no stack\n");
		return ;
	}
	
	current = stack->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
	}
	printf("\n");
}

void ft_delete_stack(t_stack **stack)
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

int ft_stack_is_sorted(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	while (node->next && node->value < node->next->value)
	{
		node = node->next;
	}

	return (node->next == NULL); // si ha llegado al final de la lista, esta ordenado
}

t_node *ft_find_min(t_stack *stack)
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

t_node *ft_find_max(t_stack *stack)
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
