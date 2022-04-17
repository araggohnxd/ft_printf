/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maolivei <maolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:39:11 by maolivei          #+#    #+#             */
/*   Updated: 2022/04/17 19:28:55 by maolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// external libraries
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// macros and enumerators
# define HEX_BASE_LOWER "0123456789abcdef"
# define HEX_BASE_UPPER "0123456789ABCDEF"

enum e_bool {
	FALSE,
	TRUE
};

enum e_types {
	INT = 2,
	CHAR,
	STR,
	PTR,
	UINT,
	HEX_L,
	HEX_U,
	PERCENT
};

// type definitions
typedef unsigned int		t_uint;
typedef unsigned long		t_ulong;

// ft_printf
int		ft_printf(const char *format, ...);

// handlers
int		ft_handler_character(char character);
int		ft_handler_decimal(int decimal);
int		ft_handler_hex_lower(t_uint num);
int		ft_handler_hex_upper(t_uint num);
int		ft_handler_percent(void);
int		ft_handler_pointer(t_ulong pointer_size);
int		ft_handler_string(char *string);
int		ft_handler_unsigned(t_uint uint);

// utils
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa_base(t_ulong n, char *base);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(long n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif
