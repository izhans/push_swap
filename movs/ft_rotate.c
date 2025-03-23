/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:57:51 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/23 12:22:30 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_stack *stack);

void	ft_ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	printf("ra\n");
}

void	ft_rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	printf("rb\n");
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	printf("rr\n");
}

/**
 * 1 2 3 -> 2 3 1
 * detach and update head
 * attach head to tail and update tail
 */
static void	ft_rotate(t_stack *stack)
{
	t_node	*current_head;
	t_node	*current_tail;
	t_node	*head_next;

	current_head = stack->head;
	current_tail = stack->tail;
	head_next = stack->head->next;
	current_head->next = NULL;
	head_next->prev = NULL;
	stack->head = head_next;
	current_tail->next = current_head;
	current_head->prev = current_tail;
	stack->tail = current_head;
}
