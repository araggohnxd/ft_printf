/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 21:18:51 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/15 13:00:29 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(t_ulong n, char *base)
{
	char		*arr;
	t_ulong		num;
	size_t		num_size;
	size_t		base_size;

	num = n;
	num_size = 1;
	base_size = ft_strlen(base);
	while (n >= base_size)
	{
		n /= base_size;
		num_size++;
	}
	arr = ft_calloc((num_size + 1), sizeof(char));
	if (arr == NULL)
		return (NULL);
	while (num_size--)
	{
		arr[num_size] = base[num % base_size];
		num /= base_size;
	}
	return (arr);
}
