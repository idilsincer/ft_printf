/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 16:43:45 by idilsincer        #+#    #+#             */
/*   Updated: 2026/09/02 16:36:47 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;
	size_t	sum;

	i = 0;
	sum = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size > dst_len)
		sum = dst_len + src_len;
	else
		sum = src_len + size;
	while (src[i] && size > (dst_len + 1))
	{
		dst[dst_len] = src[i];
		dst_len++;
		i++;
	}
	dst[dst_len] = '\0';
	return (sum);
}
