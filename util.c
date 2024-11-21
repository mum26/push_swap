/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:35:05 by sishige           #+#    #+#             */
/*   Updated: 2024/11/21 17:59:14 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_odd_in_ternary(int num)
{
	int	ternary_digit;
	int	remainder;

	ternary_digit = get_u_num_of_digit_base(num, 3);
	remainder = ternary_digit % 2;
	return (remainder);
}

int	is_duplicate(int n, t_list *sentinel)
{
	t_list	*current;
	if (sentinel == NULL)
		return (false);
	current = sentinel->next;
	while (current)
	{
		if (current->content == NULL)
			break ;
		if (((t_contents *)current->content)->num == n)
			return (true);
		current = current->next;
	}
	return (false);
}

int	is_sorted(t_list *sentinel)
{
	t_list	*current;

	if (sentinel == NULL)
		return (false);
	current = sentinel->next;
	while(current)
	{
		if (current->next == NULL || current->next->content == NULL)
			break ;
		if (((t_contents *)current->content)->num
				> ((t_contents *)current->next->content)->num)
			return (false);
		current = current->next;
	}
	return (true);
}

int	is_quoting(char *argv)
{
	size_t	n;
	char	*p;

	p = argv;
	n = count_words(p, ' ');
	if (0 < n)
		return (true);
	return (false);
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

