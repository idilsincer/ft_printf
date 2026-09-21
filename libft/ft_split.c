/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idsincer <idsincer@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:07:49 by idsincer          #+#    #+#             */
/*   Updated: 2026/09/20 15:10:27 by idsincer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_counter(char const *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static int	word_maker(char const **str, char c, char **arr, size_t i)
{
	size_t	len;

	while (**str == c)
		(*str)++;
	len = 0;
	while ((*str)[len] && (*str)[len] != c)
		len++;
	arr[i] = ft_substr(*str, 0, len);
	if (!arr[i])
		return (0);
	*str += len;
	return (1);
}

static void	free_value(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char const	*str;
	char		**arr;
	size_t		i;
	size_t		count;

	if (!s)
		return (NULL);
	str = s;
	count = word_counter(s, c);
	arr = ft_calloc(count + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (!word_maker(&str, c, arr, i))
			return (free_value(arr), NULL);
		i++;
	}
	return (arr);
}
