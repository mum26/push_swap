/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:35:05 by sishige           #+#    #+#             */
/*   Updated: 2024/10/28 18:01:17 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int mapping(int n, int offset)
{
	unsigned int	un;

	un = (unsigned int)(n + offset);
	return (un);
}

char	*ulong_to_ternary(char *ternary, unsigned long ul)
{
	int		len;
	size_t	base_len;

	if (ternary == NULL)
		return (NULL);
	len = INT_TERNARY_MAX_LEN - 1;
	ternary[len--] = '\0';
	base_len = ft_strlen(TER_DIGITS);
	while (0 <= len)
	{
		if (0 < ul)
		{
			ternary[len--] = TER_DIGITS[ul % base_len];
			ul /= base_len;
		}
		else
			ternary[len--] = '0';
	}
	return (ternary);
}

char	*parse_sign(char *str, int *sign)
{
	if (str == NULL || sign == NULL)
		return (NULL);
	while (ft_isspace(*str))
		str++;
	*sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	return (str);
}

int	safe_atoi(int *n, char *str)
{
	int			sign;
	long long	lln;
	char		*s;

	if (n == NULL || str == NULL)
		return (FUNC_FAILUER);
	s = parse_sign(str, &sign);
	if (*s == '\0')
		return (FUNC_FAILUER);
	lln = 0;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (FUNC_FAILUER);
		lln = lln * 10 + (*s - '0');
		s++;
		if (ft_isdigit(*s) && sign == 1 && ((INT_MAX - (*s - '0'))
				/ 10 < lln || lln * 10 >= INT_MAX))
			return (FUNC_FAILUER);
		if (ft_isdigit(*s) && sign == -1 && ((INT_MIN + (*s - '0'))
				/ 10 > -lln || lln * 10 < INT_MIN))
			return (FUNC_FAILUER);
	}
	*n = sign * (int)lln;
	return (FUNC_SUCCESS);
}

void	set_min(int num, unsigned int *min)
{
	unsigned int	temp;

	temp = 0;
	if (num < 0)
		temp = num * -1;
	if (*min < temp)
		*min = temp;
}
