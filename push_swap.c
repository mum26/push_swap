/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/10/24 23:09:19 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ulong_to_ternary(char *ternary, unsigned long ul)
{
	int		len;
	size_t	base_len;

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

	s = str;
	s = parse_sign(s, &sign);
	lln = 0;
	while (ft_isdigit(*s))
	{
		lln = lln * 10 + (*s - '0');
		s++;
		if (ft_isdigit(*s) && sign == 1 && ((INT_MAX - (*s - '0'))
				/ 10 < lln || lln * 10 >= INT_MAX))
			return (1);
		if (ft_isdigit(*s) && sign == -1 && ((INT_MIN + (*s - '0'))
				/ 10 > -lln || lln * 10 < INT_MIN))
			return (1);
	}
	*n = sign * (int)lln;
	return (0);
}

void	free_contents(void *contents)
{
	if (contents == NULL)
		return ;
	free((t_contents *)contents);
	contents = NULL;
}

t_contents	*make_contents(char *str)
{
	t_contents	*contents;
	contents = (t_contents *)malloc(sizeof(t_contents));
	if (contents == NULL)
		return (NULL);
	contents->str = str;
	if (safe_atoi(&contents->num, str))
		return (free(contents), NULL);
	return (contents);
}

t_list	*make_node(t_list *sentinel, char *argv)
{
	t_list		*new_node;
	t_contents	*new_contents;

	new_contents = make_contents(argv);
	if (new_contents == NULL)
		return (NULL);
	new_node = ft_lstnew(new_contents);
	if (new_node == NULL)
		return (free_contents(new_contents), NULL);
	new_node->prev = sentinel->prev;
	new_node->next = sentinel;
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
		stack_a->next = make_node(sentinel, argv[i]);
		if (stack_a->next == NULL)
		{
			ft_lstclear(&sentinel, &free_contents);
			die("malloc error");
		}
		stack_a = stack_a->next;
		sentinel->prev = stack_a;
		i++;
	}
}

void	init_stacks(t_list **stack_a, t_list **stack_b, int argc, char *argv[])
{
	*stack_a = (t_list *)malloc(sizeof(t_list));
	if (*stack_a == NULL)
		return ;
	(*stack_a)->content = NULL;
	(*stack_a)->prev = *stack_a;
	(*stack_a)->next = *stack_a;
	init_stack_a(*stack_a, argc, argv);
	*stack_b = (t_list *)malloc(sizeof(t_list));
	(*stack_b)->content = NULL;
	(*stack_b)->prev = *stack_b;
	(*stack_b)->next = *stack_b;
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*current;

	init_stacks(&stack_a, &stack_b, argc, argv + 1);
	print_lst("stack_a", stack_a);
	current = stack_a->next;
	while (current->content != NULL)
	{
		print_lst("stack_a", current);
		current = current->next;
	}
	print_lst("stack_a", current);
	ft_lstclear(&stack_a, &free_contents);
	free(stack_b);
	return (0);
}

