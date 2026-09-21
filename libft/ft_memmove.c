/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 17:17:02 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/02 18:31:50 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if ((unsigned char *)dest <= (unsigned char *)src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			n--;
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
		}
	}
	return (dest);
}
