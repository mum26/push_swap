/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:46:04 by sishige           #+#    #+#             */
/*   Updated: 2024/10/25 22:11:08 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	fail_init_stack_a(t_list *sentinel, t_list *stack_a)
{
	stack_a->next = sentinel;
	sentinel->prev = stack_a;
	ft_lstclear(&sentinel, &free_contents);
	return (FUNC_FAILUER);
}

void	set_offset(int num, unsigned int *min)
{
	unsigned int	temp;

	if (num < 0)
		temp = num * -1;
	if (min < temp)
		min = temp;
}

int	init_stack_a(t_list *stack_a, int argc, char *argv[])
{
	t_list			*sentinel;
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
		stack_a->next = make_node(sentinel, argv[i++]);
		if (stack_a->next == NULL)
			return (fail_init_stack_a(sentinel, stack_a));
		stack_a = stack_a->next;
		sentinel->prev = stack_a;
		set_min(((t_contents *)stack_a->content)->num, &min);
	}
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
