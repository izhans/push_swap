/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 03:16:18 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/12 13:58:07 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c);
static int	ft_isdigit(int c);

// TODO change name -> ft_init_arg ?
// ! this function is getting many responsibilities
/**
 * @brief takes an string argument, converts it to an int
 * 		checks if the number is valid (is an int and its not duplicated)
 * 		and adds it to the stack
 */
// ? puedo ahorrarme el devolver el numero ?? total, ya estoy metiendolo en el stack aqui
int	ft_atoi(char *str, t_stack *stack)
{
	long	n;
	int		sign;

	if (ft_strlen(str) > 12)
		ft_exit();
	
	n = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
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
	// errores: ha terminado de sacar numero y quedan caracteres, mayor que MAX_INT, menor que MIN_INT, duplicado
	if (*str || n > INT_MAX || n < INT_MIN || ft_value_exists(stack, n))
	{
		printf("error %s < %ld", str, n);
		ft_free_and_exit(stack);
	}

	ft_new_node(stack, n);
	
	return (n);
}

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
