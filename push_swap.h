/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:24:22 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/05 17:14:35 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // TODO delete

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

typedef struct node
{
	struct node	*prev;
	struct node	*next;
	int			value;
} t_node;

//movs (pa, ra, ...)

// utils
#include <stdlib.h>
#include <limits.h>

char	**ft_split(char const *s, char c);
int	ft_atoi(char *str);
size_t	ft_strlen(const char *s);

/*
void	ft_swap(t_node *stack);
void	ft_push(t_node *src_stack, t_node *dest_stack);
// rotate & rev rotate -> pasar head y tail en vez de stack
void	ft_rotate(t_node *stack);
void	ft_reverse_rotate(t_node *stack);
*/

#endif
