/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 19:57:51 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/11 20:56:02 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate(t_stack *stack);

void ft_ra(t_stack *stack_a)
{
	ft_rotate(stack_a);
	printf("ra\n");
}

void ft_rb(t_stack *stack_b)
{
	ft_rotate(stack_b);
	printf("rb\n");
}

void ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	printf("rr\n");
}

// 1 2 3 -> 2 3 1
static void	ft_rotate(t_stack *stack)
{
	if (!stack || stack->head == NULL || stack->head == stack->tail)
	{
		printf("! ret ");
		return ;
	}
	
	t_node *current_head = stack->head;
	t_node *current_tail = stack->tail;
	t_node *head_next = stack->head->next;

	// detach and update head
	current_head->next = NULL;
	head_next->prev = NULL;
	stack->head = head_next;

	// attach head to tail and update tail
	current_tail->next = current_head;
	current_head->prev = current_tail;
	stack->tail = current_head;


	// stack->tail->next = stack->head // ahora es circular
	// stack->head->prev = stack->tail // ahora es circular tambien pa atras

	// stack->head->next->prev = null // el segundo elemento deja de tener previo para ser el primero
	// stack->head->next = null // el primer elemento deja de tener siguiente para convertirse en el último

	// stack->head = al siguiente
	// stack->tail = stack->head
}
