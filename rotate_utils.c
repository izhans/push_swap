/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:18:22 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/13 18:35:08 by isastre-         ###   ########.fr       */
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
	ft_assign_indexes(stack);
}
