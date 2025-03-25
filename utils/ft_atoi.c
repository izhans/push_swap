/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 03:16:18 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/25 21:54:18 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/**
 * @brief takes an string argument, converts it to an int
 * 		checks if the number is valid (is an int and its not duplicated)
 * 		and adds it to the stack
 */
int	ft_add_number_to_stack(char *str, t_stack *stack)
{
	long	n;
	int		sign;

	if (ft_strlen(str) > 12 || (ft_strlen(str) < 2 && !ft_isdigit(*str)))
		return (0);
	n = 0;
	sign = 1;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	n *= sign;
	if (*str || n > INT_MAX || n < INT_MIN || ft_value_exists(stack, n))
		return (0);
	return (ft_new_node(stack, n));
}
