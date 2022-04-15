/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 09:57:14 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/14 17:06:19 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handler_string(char *string)
{
	if (!string)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(string, 1);
	return (ft_strlen(string));
}
