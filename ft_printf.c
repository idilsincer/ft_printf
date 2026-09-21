/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:15:14 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/20 17:32:19 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void print(void *s)
{
	char	*str = (char *)s;
	size_t	i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	size_t	i;
	
	va_start(args, format);
	i = 0;
	
}
merhaba %s nasılsın %d idil, 42