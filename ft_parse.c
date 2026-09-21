/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 17:09:21 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/20 17:33:01 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_parse(const char *format, size_t len)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	len = find_percent(format);
	while (format[i])
	{
		while (format[i] != '%')
			i++;
		str = ft_substr(format, *str, i);
		*str +=i;
		i++;
	}
	return str;
}
