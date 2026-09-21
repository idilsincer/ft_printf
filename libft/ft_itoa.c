/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:53:46 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/07 22:36:29 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_base(long number)
{
	size_t	counter;

	counter = 0;
	if (number <= 0)
		counter++;
	while (number != 0)
	{
		number /= 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	number;
	size_t	len;

	number = n;
	len = find_base(number);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	if (number == 0)
		str[0] = '0';
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	while (number > 0)
	{
		str[--len] = (number % 10) + '0';
		number /= 10;
	}
	return (str);
}
