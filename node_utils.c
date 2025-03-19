/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:00 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/20 00:35:57 by isastre-         ###   ########.fr       */
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
	t_node 				*new_node;
	static unsigned int	index;

	new_node = malloc(sizeof(t_node));
	new_node->value = value;
	new_node->next = NULL;
	
	if (!stack->head)
	{
		new_node->prev = NULL; // ? 1
		stack->head = new_node;
	}
	else
	{	
		new_node->prev = stack->tail; // ? 1 esto seria NULL en el caso de !stack->head ?
		stack->tail->next = new_node;
	}
	stack->tail = new_node;
	new_node->index = index;
	index++;
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
		printf("%d: %d ->", current->index, current->value);
		if (!current->target)
			printf("NULL");
		else
			printf("%d", current->target->value);
		printf(" $%u", current->cost);
		printf("\n");
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

unsigned int ft_stack_size(t_stack *stack)
{
	unsigned int	size;
	t_node 			*current;

	size = 0;
	current = stack->head; // ! segfaults if !stack
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void ft_assign_indexes(t_stack *stack)
{
	unsigned int	index;
	t_node 			*current;

	index = 0;
	current = stack->head; // ! segfaults if !stack
	while (current)
	{
		current->index = index;
		index++;
		current = current->next;
	}
}

static t_node *ft_find_target_node(t_stack *stack, t_node *node)
{
	t_node	*current;
	t_node	*target;

	current = stack->head; // ! segfaults if !stack
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

void ft_assign_target_nodes(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current;

	current = stack_b->head; // ! segfaults if !stack
	while (current)
	{
		current->target = ft_find_target_node(stack_a, current);
		current = current->next;
	}
}

static unsigned int ft_calc_node_cost(t_node *node, unsigned int stack_size)
{
	if (node->index <= stack_size/2)
		return (node->index);
	return (stack_size - node->index);
}

void ft_assign_costs(t_stack *stack)
{
	unsigned int	stack_size;
	t_node			*current;

	stack_size = ft_stack_size(stack);
	current = stack->head; // ! segfaults if !stack
	while (current)
	{
		current->cost = ft_calc_node_cost(current, stack_size);
		current = current->next;
	}
}

static unsigned int ft_get_total_cost(t_node *node)
{
	return (node->cost + node->target->cost);
}

t_node *ft_find_cheapest(t_stack *stack)
{
	t_node			*current;
	t_node			*cheapest;

	current = stack->head; // ! segfaults if !stack
	cheapest = stack->head;
	while (current)
	{
		if (ft_get_total_cost(current) < ft_get_total_cost(cheapest))
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
