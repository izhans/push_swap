/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:18:22 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/20 01:02:55 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cheapest_rotate_a(t_stack *stack, t_node *node)
{
	unsigned int	size;
	unsigned int	index;
	
	// calcular stack size
	size = ft_stack_size(stack);
	index = node->index;
	// ver si el nodo a girar esta por encima o por debajo de la mitad
	// rotar en la direccion elegida hasta que sea el primero
	while (index != 0 && index != size)
	{
		if (index <= size/2)
		{
			ft_ra(stack);
			index--;
		}
		else
		{
			ft_rra(stack);
			index++;
		}
	}
}

void	ft_cheapest_rotate_b(t_stack *stack, t_node *node)
{
	unsigned int	size;
	unsigned int	index;
	
	// calcular stack size
	size = ft_stack_size(stack);
	index = node->index;
	// ver si el nodo a girar esta por encima o por debajo de la mitad
	// rotar en la direccion elegida hasta que sea el primero
	while (index != 0 && index != size)
	{
		if (index <= size/2)
		{
			ft_rb(stack);
			index--;
		}
		else
		{
			ft_rrb(stack);
			index++;
		}
	}
}

void	ft_cheapest_rotate(t_stack *stack_a, t_stack *stack_b, t_node *cheapest)
{
	unsigned int	size_a;
	unsigned int	size_b;

	size_a = ft_stack_size(stack_a);
	size_b = ft_stack_size(stack_b);
	if (cheapest->index <= size_b/2 && cheapest->target->index <= size_a/2)
	{
		while (stack_a->head != cheapest->target && stack_b->head != cheapest)
			ft_rr(stack_a, stack_b);
	}
	else if (cheapest->index > size_b/2 && cheapest->target->index > size_a/2)
	{
		while (stack_a->head != cheapest->target && stack_b->head != cheapest)
			ft_rrr(stack_a, stack_b);
	}
	// actualizo indexs para acabar la rotacion
	ft_assign_indexes(stack_a);
	ft_assign_indexes(stack_b);

	if (stack_a->head != cheapest->target)
		ft_cheapest_rotate_a(stack_a, cheapest->target);
	if (stack_b->head != cheapest)
		ft_cheapest_rotate_b(stack_b, cheapest);
}
