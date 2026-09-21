/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 16:30:14 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/20 16:38:58 by idsincer         ###   ########.fr       */
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
	write(1, '\n', 1);
}
char	*ft_printstr(const char *str)
{
	ft_striter(str, print);
	
}