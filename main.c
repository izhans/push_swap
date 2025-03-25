/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:20:21 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/25 23:26:39 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stack_a(char *argv[], int split, t_stack **stack_a);
static void	ft_free(t_stack *stack_a, char **splited);
static void	ft_exec_algorithm(t_stack *stack_a, t_stack *stack_b);

/**
 * @brief 	creates stacks, populates stack_a with the program input,
 * 			selects sort and frees stacks at the end
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
	ft_init_stack_a(argv, argc == 2, &stack_a);
	if (ft_stack_is_sorted(stack_a))
	{
		ft_delete_stack(&stack_a);
		return (0);
	}
	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (ft_free_stack_and_exit(stack_a), 1);
	stack_b->head = NULL;
	stack_b->tail = NULL;
	ft_exec_algorithm(stack_a, stack_b);
	ft_delete_stack(&stack_a);
	ft_delete_stack(&stack_b);
	return (0);
}

/**
 * @brief creates and populates stack_a
 */
static void	ft_init_stack_a(char *argv[], int split, t_stack **stack_a)
{
	char	**splited;

	splited = NULL;
	if (split)
	{
		splited = ft_split(*argv, ' ');
		if (splited == NULL || *splited == NULL)
			ft_exit();
		argv = splited;
	}
	*stack_a = malloc(sizeof(t_stack));
	if (*stack_a == NULL)
		return (ft_free(*stack_a, splited));
	(*stack_a)->head = NULL;
	(*stack_a)->tail = NULL;
	while (*argv)
	{
		if (!ft_add_number_to_stack(*argv, *stack_a))
			return (ft_free(*stack_a, splited));
		argv++;
	}
	ft_free_str_array(splited);
}

static void	ft_free(t_stack *stack_a, char **splited)
{
	ft_free_str_array(splited);
	ft_free_stack_and_exit(stack_a);
}

static void	ft_exec_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	unsigned int	numbers;

	numbers = ft_stack_size(stack_a);
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
}
