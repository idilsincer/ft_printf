/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:26:27 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/09 14:27:08 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	s_length;
	size_t	i;

	if (!s)
		return (0);
	s_length = ft_strlen(s);
	if (start >= s_length)
		len = 0;
	else if (len > s_length - start)
		len = s_length - start;
	substring = ft_calloc(len + 1, sizeof(char));
	if (!substring)
		return (0);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
