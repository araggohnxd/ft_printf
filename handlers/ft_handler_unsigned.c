/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:51:07 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/14 15:49:37 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler_unsigned(t_uint uint)
{
	size_t	num_size;

	num_size = 1;
	ft_putnbr_fd(((long) uint), 1);
	while (uint >= 10)
	{
		uint /= 10;
		num_size++;
	}
	return (num_size);
}
