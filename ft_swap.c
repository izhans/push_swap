/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:33:58 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/12 17:08:00 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swap(t_stack *stack);

void ft_sa(t_stack *stack_a)
{
	ft_swap(stack_a);
	printf("sa\n");
}

void ft_sb(t_stack *stack_b)
{
	ft_swap(stack_b);
	printf("sb\n");
}

void ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	printf("ss\n");
}

static void ft_swap(t_stack *stack)
{
	if (!stack || stack->head == NULL || stack->head == stack->tail)
	{
		printf("! ret ");
		return ;
	}
	
	t_node *first = stack->head;
	t_node *second = first->next;
	t_node *third = second->next;

	// detach first
	first->next = NULL;
	second ->prev = NULL;

	// attach first to third
	first->next = third;
	// ! si solo hay 2 nodos hay que cambiar el stack->tail
	if (stack->tail == second)
		stack->tail = first;
	else
		third->prev = first;

	// attach second at the beggining
	second->next = first;
	first->prev = second;
	
	// move head
	stack->head = second;
}
