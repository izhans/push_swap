/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 03:16:18 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/06 12:49:43 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c);
static int	ft_isdigit(int c);
void ft_exit(); // TODO move to another file

int	ft_atoi(char *str)
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
	// TODO error duplicados
	if (*str || n > INT_MAX || n < INT_MIN)
	{
		printf("error %s < %ld", str, n);
		ft_exit();
	}
	
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

void ft_exit()
{
	// TODO print Error\n in stderror
	exit(1);
}