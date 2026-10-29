/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idil <idil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:36:10 by idil              #+#    #+#             */
/*   Updated: 2026/10/29 16:50:33 by idil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

int	print_base(unsigned long n, char *base)
{
	size_t	len;

	len = 1;
	if (n >= ft_strlen(base))
		len += print_base(n / ft_strlen(base), base);
	ft_putchar_fd(base[n % ft_strlen(base)], 1);
	return (len);
}

int	print_int(int n)
{
	char	*s;
	size_t	len;

	s = ft_itoa(n);
	if (!s)
		return (-1);
	len = print_str(s);
	free(s);
	return (len);
}

int	print_ptr(void *ptr)
{
	if (!ptr)
		return (print_str("(nil)"));
	ft_putstr_fd("0x", 1);
	return (2 + print_base((unsigned long)ptr, "0123456789abcdef"));
}
