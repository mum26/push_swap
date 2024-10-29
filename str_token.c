/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:49:49 by sishige           #+#    #+#             */
/*   Updated: 2024/10/29 15:15:18 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_words(char const *str, char c)
{
	size_t	cnt;
	size_t	in_word;

	cnt = 0;
	in_word = 0;
	while (*str)
	{
		if (*str == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			cnt++;
		}
		str++;
	}
	return (cnt);
}

static size_t	get_next_substr_len(char const **str, char c)
{
	size_t		len;
	char const	*start;

	len = 0;
	while (**str && **str == c)
		(*str)++;
	start = *str;
	while (**str && **str != c)
	{
		(*str)++;
		len++;
	}
	if (*str > start)
		return (len);
	return (0);
}

static int	exec_split(char **dst, char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		len = get_next_substr_len(&s, c);
		if (len == 0)
			continue ;
		dst[i] = ft_substr(s - len, 0, len);
		if (dst[i++] == NULL)
			return (cleanup(dst), FUNC_FAILUER);
	}
	dst[i] = NULL;
	return (FUNC_SUCCESS);
}

int	str_token(char ***dst, char const *s, char c)
{
	size_t	words;

	if (s == NULL || dst == NULL)
		return (-1);
	words = count_words(s, c);
	if (0 == words)
		return (0);
	*dst = (char **)malloc(sizeof(char *) * (words + 1));
	if (*dst == NULL)
		return (-1);
	if (exec_split(*dst, s, c))
		return (-1);
	return (words + 1);
}
