/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:39:10 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/17 19:26:45 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_this(int type, va_list ap, size_t *size)
{
	if (type == INT)
		*size += ft_handler_decimal(va_arg(ap, int));
	else if (type == CHAR)
		*size += ft_handler_character(va_arg(ap, int));
	else if (type == STR)
		*size += ft_handler_string(va_arg(ap, char *));
	else if (type == PTR)
		*size += ft_handler_pointer((t_ulong) va_arg(ap, void *));
	else if (type == UINT)
		*size += ft_handler_unsigned(va_arg(ap, t_uint));
	else if (type == HEX_L)
		*size += ft_handler_hex_lower(va_arg(ap, t_uint));
	else if (type == HEX_U)
		*size += ft_handler_hex_upper(va_arg(ap, t_uint));
	else if (type == PERCENT)
		*size += ft_handler_percent();
	else
		return (FALSE);
	return (TRUE);
}

static int	ft_get_arg_type(char type)
{
	if (!type)
		return (FALSE);
	if (type == 'd' || type == 'i')
		return (INT);
	else if (type == 'c')
		return (CHAR);
	else if (type == 's')
		return (STR);
	else if (type == 'p')
		return (PTR);
	else if (type == 'u')
		return (UINT);
	else if (type == 'x')
		return (HEX_L);
	else if (type == 'X')
		return (HEX_U);
	else if (type == '%')
		return (PERCENT);
	return (FALSE);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	size;
	int		type;

	size = 0;
	va_start(ap, format);
	while (*format && *format - 1 != '\0')
	{
		type = 0;
		while (*format != '%' && *format)
		{
			ft_putchar_fd(*format++, 1);
			size++;
		}
		if (*format == '%')
			type = ft_get_arg_type(*++format);
		if (!ft_handle_this(type, ap, &size))
			break ;
		format++;
	}
	va_end(ap);
	return (size);
}
