/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer < idsincer@student.42istanbul.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:58:50 by idsincer          #+#    #+#             */
/*   Updated: 2026/10/29 16:58:54 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_type(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1), 1);
	else if (type == 's')
		return (print_str(va_arg(args, char *)));
	else if (type == 'i' || type == 'd')
		return (print_int(va_arg(args, int)));
	else if (type == 'u')
		return (print_base(va_arg(args, unsigned int), "0123456789"));
	else if (type == 'x')
		return (print_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (print_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (type == 'p')
		return (print_ptr(va_arg(args, void *)));
	else if (type == '%')
		return (ft_putchar_fd('%', 1), 1);
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		check;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			check = find_type(*(++format), args);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			len++;
		}
		format++;
	}
	va_end(args);
	return (len);
}
