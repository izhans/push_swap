/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_number_to_stack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 03:16:18 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/26 00:00:39 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_value_exists(t_stack *stack, int value);
static int	ft_new_node(t_stack *stack, int value);

/**
 * @brief takes an string argument, converts it to an int
 * 		checks if the number is valid (is an int and its not duplicated)
 * 		and adds it to the stack
 */
int	ft_add_number_to_stack(char *str, t_stack *stack)
{
	long	n;
	int		sign;

	if (ft_strlen(str) > 12 || (ft_strlen(str) < 2 && !ft_isdigit(*str)))
		return (0);
	n = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	n *= sign;
	if (*str || n > INT_MAX || n < INT_MIN || ft_value_exists(stack, n))
		return (0);
	return (ft_new_node(stack, n));
}

/**
 * @return 0 if value doesn't exist, 1 if it alredy exists
 */
static int	ft_value_exists(t_stack *stack, int value)
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

static int	ft_new_node(t_stack *stack, int value)
{
	t_node				*new_node;
	static unsigned int	index = 0;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (0);
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
	return (1);
}
