/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 22:14:55 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/23 12:22:21 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push(t_stack *origin, t_stack *dest);

// Toma el primer elemento del stack b y lo pone el primero en el stack a.
// No hace nada si b está vacío
void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_b, stack_a);
	printf("pa\n");
}

// Toma el primer elemento del stack a y lo pone el primero en el stack b. 
// No hace nada si a está vacío.
void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_push(stack_a, stack_b);
	printf("pb\n");
}

/**
 * detach node from origin and update stack head [+ tail]
 * 		updates head and tail to NULL if its the only node on the list
 * attach node to dest
 */
static void	ft_push(t_stack *origin, t_stack *dest)
{
	t_node	*node;

	node = origin->head;
	if (node->next)
	{
		origin->head = node->next;
		node->next->prev = NULL;
		node->next = NULL;
	}
	else
	{
		origin->head = NULL;
		origin->tail = NULL;
	}
	if (dest->head)
	{
		node->next = dest->head;
		dest->head->prev = node;
	}
	else
		dest->tail = node;
	dest->head = node;
}
