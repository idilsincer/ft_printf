/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 15:29:51 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/09 13:07:08 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*number_of_members;

	if (nmemb != 0 && (nmemb * size) / nmemb != size)
		return (0);
	number_of_members = malloc(nmemb * size);
	if (!number_of_members)
		return (0);
	ft_bzero(number_of_members, nmemb * size);
	return (number_of_members);
}
