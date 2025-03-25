/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:01:20 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/25 23:22:01 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rev_rotate(t_stack *stack);

void	ft_rra(t_stack *stack_a)
{
	ft_rev_rotate(stack_a);
	ft_putendl("rra");
}

void	ft_rrb(t_stack *stack_b)
{
	ft_rev_rotate(stack_b);
	ft_putendl("rrb");
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_putendl("rrr");
}

/**
 * 1 2 3 -> 3 1 2
 * detach and update tail
 * attach tail to head and update head
 */
static void	ft_rev_rotate(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;
	t_node	*tail_prev;

	head = stack->head;
	tail = stack->tail;
	tail_prev = stack->tail->prev;
	tail->prev = NULL;
	tail_prev->next = NULL;
	stack->tail = tail_prev;
	head->prev = tail;
	tail->next = head;
	stack->head = tail;
}
