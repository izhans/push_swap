/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:20:21 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/11 20:56:37 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int main(int argc, char *argv[])
{
	if (argc == 1)
		return (1); // error: no input params
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		printf("splitted\n");
		
		// while (*argv)
		// {
		// 	printf("<%s>\n", *argv);
		// 	argv++;
		// }
		
	}
	if (argc > 2) // TODO cambiar por else
		argv++; // para saltar el nombre del programa
	
	int n;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	stack_b->head = NULL;
	stack_b->tail = NULL;
	
	while (*argv)
	{
		n = ft_atoi(*argv, stack_a);
		argv++;
	}

	// PRUEBAS rotate
	ft_new_node(stack_b, 4);
	ft_new_node(stack_b, 5);
	// ft_new_node(stack_b, 6);

	ft_print_stack(stack_a, 'a');
	ft_ra(stack_a);
	ft_print_stack(stack_a, 'a');
	printf("--------------------------------------\n");

	ft_print_stack(stack_b, 'b');
	ft_rb(stack_b);
	ft_print_stack(stack_b, 'b');
	printf("--------------------------------------\n");

	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	ft_rr(stack_a, stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	
	ft_rr(stack_a, stack_b);
	ft_print_stack(stack_a, 'a');
	ft_print_stack(stack_b, 'b');
	
	return 0;
}

