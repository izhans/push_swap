/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:20:21 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/12 13:18:27 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief inits stacks and populates stack_a with the program input
 * @returns 1 if no input params
 * 			0 if program execs till the end
 */
int	main(int argc, char *argv[])
{
	int		n;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (1);
	argv++;
	if (argc == 2)
		argv = ft_split(*argv, ' ');
	
	// stacks init
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_b->head = NULL;
	stack_b->tail = NULL;
	
	// populate stack_a
	while (*argv)
	{
		n = ft_atoi(*argv, stack_a); // ! n no se esta usando
		argv++;
	}

	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	
	return (0);
}
