/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:20:21 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/06 14:22:48 by isastre-         ###   ########.fr       */
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
	t_stack *stack;

	stack = malloc(sizeof(t_stack));
	while (*argv)
	{
		n = ft_atoi(*argv, stack);
		argv++;
	}

	printf("stack\n");
	while (stack->head)
	{
		printf("%d\n", stack->head->value);
		stack->head = stack->head->next;
	}
	
	return 0;
}

