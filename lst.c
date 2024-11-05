/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:46:04 by sishige           #+#    #+#             */
/*   Updated: 2024/11/05 19:21:12 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_lst(t_list **lst)
{
	if (lst == NULL)
		return (FUNC_FAILUER);
	*lst = (t_list *)malloc(sizeof(t_list));
	if (*lst == NULL)
		return (FUNC_FAILUER);
	(*lst)->content = NULL;
	(*lst)->prev = *lst;
	(*lst)->next = *lst;
	return (FUNC_SUCCESS);
}

void	make_stack_a(t_list **stack_a, int *argc, char *argv[])
{
	char	**strv;

	strv = argv;
	if (stack_a == NULL)
		die("Error");
	if (make_lst(stack_a))
		die("Error");
	if (*argc == 2 && is_quoting(argv[0]))
	{
		*argc = str_token(&strv, argv[0], ' ');
		if (argv == NULL)
			die("Error");
	}
	if (init_stack_a(*stack_a, *argc, strv))
	{
		if (argv != strv)
			cleanup(strv);
		die("Error");
	}
	if (argv != strv)
		cleanup(strv);
}

t_list	*make_node(t_list *sentinel, char *argv)
{
	t_list		*new_node;
	t_contents	*new_contents;

	if (sentinel == NULL || argv == NULL)
		return (NULL);
	new_contents = make_contents(argv, sentinel);
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
	return (true);
}

int	init_stack_a(t_list *stack_a, int argc, char *argv[])
{
	t_list			*current;
	t_list			*new_node;
	t_list			*head;
	size_t			i;

	if (stack_a == NULL || argv == NULL)
		return (FUNC_FAILUER);
	current = stack_a;
	head = stack_a->next;
	i = 0;
	while (i < (size_t)argc - 1)
	{
		new_node = make_node(stack_a, argv[i++]);
		if (new_node == NULL)
			return (fail_init_stack_a(stack_a, current));
		current->next = new_node;
		head->prev = new_node;
		current = current->next;
	}
	lstiter_num_to_ternary(stack_a, argc - 1);
	return (FUNC_SUCCESS);
}

