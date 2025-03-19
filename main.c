/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:20:21 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/19 22:06:01 by isastre-         ###   ########.fr       */
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
		argv = ft_split(*argv, ' '); // TODO hay que liberar esta memoria
	
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

	if (ft_stack_is_sorted(stack_a))
	{
		ft_delete_stack(&stack_a);
		return (0);
	}
	
	// create stack_b
	stack_b = malloc(sizeof(t_stack));
	stack_b->head = NULL;
	stack_b->tail = NULL;

	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');

	unsigned int	numbers = ft_stack_size(stack_a);
	if (numbers == 2)
		ft_sa(stack_a);
	else if (numbers == 3)
		ft_sort_three(stack_a);
	else if (numbers == 4)
		ft_sort_four(stack_a, stack_b);
	else if (numbers == 5)
		ft_sort_five(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);
		
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	// free stacks
	ft_delete_stack(&stack_a);
	ft_delete_stack(&stack_b);
	return (0);
}
