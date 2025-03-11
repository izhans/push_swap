/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:01:20 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/11 21:14:54 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_rev_rotate(t_stack *stack);

void ft_rra(t_stack *stack_a)
{
	ft_rev_rotate(stack_a);
	printf("rra\n");
}

void ft_rrb(t_stack *stack_b)
{
	ft_rev_rotate(stack_b);
	printf("rrb\n");
}

void ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	printf("rrr\n");
}

// 1 2 3 -> 3 1 2
static void ft_rev_rotate(t_stack *stack)
{
	if (!stack || stack->head == NULL || stack->head == stack->tail)
	{
		printf("! ret ");
		return ;
	}

	t_node *head = stack->head;
	t_node *tail = stack->tail;
	t_node *tail_prev = stack->tail->prev;

	// detach and update tail
	tail->prev = NULL;
	tail_prev->next = NULL;
	stack->tail = tail_prev;

	// attach tail to head and update head
	head->prev = tail;
	tail->next = head;
	stack->head = tail;
}
