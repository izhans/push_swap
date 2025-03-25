/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:33:58 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/25 23:22:19 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack *stack);

void	ft_sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	ft_putendl("sa");
}

void	ft_sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	ft_putendl("sb");
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_putendl("ss");
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
