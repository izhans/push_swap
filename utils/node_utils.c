/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:12:00 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/23 18:06:42 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				ft_value_exists(t_stack *stack, int value);
void			ft_new_node(t_stack *stack, int value);
void			ft_print_stack(t_stack *stack, char c); // TODO delete
void			ft_delete_stack(t_stack **stack);
int				ft_stack_is_sorted(t_stack *stack);
unsigned int	ft_stack_size(t_stack *stack);

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

void	ft_new_node(t_stack *stack, int value)
{
	t_node				*new_node;
	static unsigned int	index = 0;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (ft_free_and_exit(stack));
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->head)
		stack->head = new_node;
	else
		stack->tail->next = new_node;
	new_node->prev = stack->tail;
	stack->tail = new_node;
	new_node->index = index;
	index++;
}

void	ft_print_stack(t_stack *stack, char c) // TODO delete
{
	t_node	*current;

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
 * si ha llegado al final de la lista, esta ordenado
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
