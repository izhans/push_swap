/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:04:25 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/19 23:16:46 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	printf("ft_sort\n");
	while (ft_stack_size(stack_a) > 3)
		ft_pb(stack_a, stack_b);
	// while ft_stack_size(stack_b)
	ft_assign_indexes(stack_b);
	ft_assign_target_nodes(stack_a, stack_b);
	// find_cheapest
	// cheapest_rotate
	// pa
}
