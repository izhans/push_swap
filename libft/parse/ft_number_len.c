/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isastre- <isastre-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:22:43 by isastre-          #+#    #+#             */
/*   Updated: 2025/03/21 15:24:06 by isastre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_number_len(long n)
{
	if (n < 0)
		return (ft_number_len(n * -1) + 1);
	if (n < 10)
		return (1);
	return (ft_number_len(n / 10) + 1);
}
