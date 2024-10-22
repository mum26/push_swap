/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/10/22 21:42:18 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ulong_to_ternary(char *ternary, unsigned long ul)
{
	int		len;
	size_t	base_len;

	ft_memset(ternary, '-', INT_TERNARY_MAX_LEN - 1);
	len = INT_TERNARY_MAX_LEN - 1;
	ternary[len--] = '\0';
	if (ul == 0)
		return (ternary);
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

	str = parse_sign(str, &sign);
	lln = 0;
	while (ft_isdigit(*str))
	{
		lln = lln * 10 + (*str - '0');
		str++;
		if (ft_isdigit(*str) && sign == 1 && ((INT_MAX - (*str - '0'))
				/ 10 < lln || lln * 10 >= INT_MAX))
			return (1);
		if (ft_isdigit(*str) && sign == -1 && ((INT_MIN + (*str - '0'))
				/ 10 > -lln || lln * 10 < INT_MIN))
			return (1);
	}
	*n = sign * (int)lln;
	return (0);
}

//t_contents	*make_contents(a)

t_list	*make_node(char	*argv)
{
	t_list		*new_node;
	t_contents	*new_contents;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_contents = (t_contents *)malloc(sizeof(t_contents));
	if (new_contents == NULL)
		return (NULL);
	new_contents->str = argv;
	if (safe_atoi(&new_contents->num, argv))
		return (NULL);
	new_node->content = new_contents;
	return (new_node);
}

void	init_stack_a(t_list *stack_a, int argc, char *argv[])
{
	t_list	*sentinel;
	size_t	i;

	sentinel = stack_a;
	i = 0;
	while (i < (size_t)argc - 1)
	{
		stack_a->next = make_node(argv[i]);
		if (stack_a->next == NULL)
		{
			ft_lstclear(&sentinel, &free);
			die("malloc error");
		}
		stack_a->next->prev = stack_a;
		stack_a = stack_a->next;
		i++;
	}
}

void	init_stacks(t_list *stack_a, t_list *stack_b, int argc, char *argv[])
{
	stack_a->content = NULL;
	stack_a->prev = stack_a;
	stack_a->next = stack_a;
	init_stack_a(stack_a, argc, argv);
	stack_b->content = NULL;
	stack_b->prev = stack_b;
	stack_b->next = stack_b;
}

void	print_lst(char const *str, t_list *lst)
{
	printf("[%s] content: %p, current: %p, prev: %p, next: %p\n", \
			str, lst->content, lst, lst->prev, lst->next);
}

int	main(void)
//int	main(int argc, char *argv[])
{
	t_list	*node;

	node = make_node("1234567890");
	print_lst("node", node);
	return (0);
}

