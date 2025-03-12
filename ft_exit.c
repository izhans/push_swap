/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:57:42 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/12 13:49:16 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_exit()
{
	write(2, "Error\n", 6);
	exit(1);
}

void ft_free_and_exit(t_stack *stack)
{
	ft_delete_stack(&stack);
	ft_exit();
}
