/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:15:20 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/12 17:26:36 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @attention before calling this function, check the stack size equals 3
 */
void	ft_short_three(t_stack *stack)
{
	t_node	*min;
	t_node	*max;

	min = ft_find_min(stack);
	max = ft_find_max(stack);
	while (!ft_stack_is_sorted(stack))
	{
		if (max == stack->tail) // solo hay que ordenar los 2 primeros numeros
			ft_sa(stack);
		else if (max == stack->head)
			ft_ra(stack);
		else // max esta en medio
			ft_rra(stack);
	}
}
