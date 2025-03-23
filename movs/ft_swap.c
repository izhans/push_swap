/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:33:58 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/23 12:22:34 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack *stack);

void	ft_sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void	ft_sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}

/**
 * detach first
 * attach first to third
 * if there are only 2 nodes, must update stack->tail
 * attach second at the beggining
 * update head
 */
static void	ft_swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack->head;
	second = first->next;
	third = second->next;
	first->next = NULL;
	second ->prev = NULL;
	first->next = third;
	if (stack->tail == second)
		stack->tail = first;
	else
		third->prev = first;
	second->next = first;
	first->prev = second;
	stack->head = second;
}
