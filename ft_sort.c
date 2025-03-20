/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 22:04:25 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/20 01:05:48 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	printf("ft_sort\n");
	while (ft_stack_size(stack_a) > 3)
		ft_pb(stack_a, stack_b);
	ft_sort_three(stack_a);
	while (stack_b->head)
	{
		ft_assign_indexes(stack_a);
		ft_assign_indexes(stack_b);
		ft_assign_target_nodes(stack_a, stack_b);
		ft_assign_costs(stack_a);
		ft_assign_costs(stack_b);
		// find_cheapest
		t_node *cheapest = ft_find_cheapest(stack_b);
		printf("cheapest %d\n", cheapest->value);
		// cheapest_rotate
		ft_cheapest_rotate(stack_a, stack_b, cheapest);
		// pa
		ft_pa(stack_a, stack_b);
	}
	t_node *first = ft_find_min(stack_a);
	ft_assign_indexes(stack_a);
	ft_cheapest_rotate_a(stack_a, first);
}
