/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:20:21 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/13 18:08:46 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief 	creates stacks, populates stack_a with the program input,
 * 			frees stacks at the end
 * @returns 1 if no input params
 * 			0 if program execs till the end
 */
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	argv++;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	
	// create stack_a
	stack_a = malloc(sizeof(t_stack));
	stack_a->head = NULL;
	stack_a->tail = NULL;
	
	// populate stack_a
	while (*argv)
	{
		ft_atoi(*argv, stack_a);
		argv++;
	}

	// create stack_b
	stack_b = malloc(sizeof(t_stack));
	stack_b->head = NULL;
	stack_b->tail = NULL;

	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');

	printf("stack_a size: %d - stack_b size: %d\n", ft_stack_size(stack_a), ft_stack_size(stack_b));
	ft_sort_four(stack_a, stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	// free stacks
	ft_delete_stack(&stack_a);
	ft_delete_stack(&stack_b);
	return (0);
}
