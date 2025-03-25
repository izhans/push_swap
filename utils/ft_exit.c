/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:57:42 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/25 23:03:33 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_stack_and_exit(t_stack *stack)
{
	ft_delete_stack(&stack);
	ft_exit();
}
