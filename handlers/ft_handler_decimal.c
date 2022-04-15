/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:43:23 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/14 19:43:13 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler_decimal(int decimal)
{
	size_t	num_size;

	num_size = 1;
	ft_putnbr_fd(((long) decimal), 1);
	while (decimal >= 10 || decimal <= -10)
	{
		decimal /= 10;
		num_size++;
	}
	if (decimal < 0)
		return (num_size + 1);
	return (num_size);
}
