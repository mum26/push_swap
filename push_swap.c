/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/10/25 18:32:34 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned long mapping(int n, int offset)
{
	unsigned long	ul;

	ul = (unsigned long)(n + offset);
	return (ul);
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

void	lstiter_num_to_ternary(t_list *lst, int offset)
{
	t_contents *contents;

	contents = NULL;
	if (lst->content == NULL)
		lst = lst->next;
	while (lst)
	{
		if (lst->content == NULL)
			break ;
		contents = (t_contents *)lst->content;
		contents->map = mapping(contents->num, offset);
		ulong_to_ternary(contents->ternary, contents->map);
		lst = lst->next;
	}
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

void	free_contents(void *contents)
{
	if (contents == NULL)
		return ;
	free((t_contents *)contents);
	contents = NULL;
}

t_contents	*make_contents(char *str)
{
	if (str == NULL)
		return (NULL);
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

	if (sentinel == NULL || argv == NULL)
		return (NULL);
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

int	init_stack_a(t_list *stack_a, int argc, char *argv[])
{
	t_list			*sentinel;
	unsigned int	offset;
	unsigned int	min;
	size_t			i;

	if (stack_a == NULL || argv == NULL)
		return (FUNC_FAILUER);
	sentinel = stack_a;
	offset = 0;
	min = 0;
	i = 0;
	while (i < (size_t)argc - 1)
	{
		stack_a->next = make_node(sentinel, argv[i]);
		if (stack_a->next == NULL)
		{
			stack_a->next = sentinel;
			sentinel->prev = stack_a;
			return (ft_lstclear(&sentinel, &free_contents), FUNC_FAILUER);
		}
		stack_a = stack_a->next;
		sentinel->prev = stack_a;
		if (((t_contents *)stack_a->content)->num < 0)
			offset = ((t_contents *)stack_a->content)->num * -1;
		else
			offset = ((t_contents *)stack_a->content)->num;
		if (min < offset)
			min = offset;
		i++;
	}
	printf("%u\n", min);
	lstiter_num_to_ternary(sentinel, min);
	return (FUNC_SUCCESS);
}

void	init_stacks(t_list **stack_a, t_list **stack_b, int argc, char *argv[])
{
	if (stack_a == NULL || stack_b == NULL || argv == NULL)
		die("Error");
	*stack_a = (t_list *)malloc(sizeof(t_list));
	if (*stack_a == NULL)
		return ;
	(*stack_a)->content = NULL;
	(*stack_a)->prev = *stack_a;
	(*stack_a)->next = *stack_a;
	if (init_stack_a(*stack_a, argc, argv))
		die("Error");
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

