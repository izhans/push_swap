/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:24:22 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/06 13:50:25 by isastre-         ###   ########.fr       */
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


typedef struct stack
{
	t_node *head;
	t_node *tail;
} t_stack;


//movs (pa, ra, ...)

// utils
#include <stdlib.h>
#include <limits.h>

void ft_exit();
int	ft_value_exists(t_stack *stack, int value);
void ft_new_node(t_stack *stack, int value);

char	**ft_split(char const *s, char c);
int	ft_atoi(char *str, t_stack *stack);
size_t	ft_strlen(const char *s);

/*
void	ft_swap(t_node *stack);
void	ft_push(t_node *src_stack, t_node *dest_stack);
// rotate & rev rotate -> pasar head y tail en vez de stack
void	ft_rotate(t_node *stack);
void	ft_reverse_rotate(t_node *stack);
*/

#endif
