/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:46:04 by sishige           #+#    #+#             */
/*   Updated: 2024/10/29 17:07:54 by sishige          ###   ########.fr       */
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

int	is_split(char *argv)
{
	size_t words;
	char	*p;

	p = argv;
	words = count_words(p, ' ');
	if (words <= 1)
		return (0);
	return (words);

}

void	make_stack_a(t_list **stack_a, int argc, char *argv[])
{
//	char	**strv;

//	strv = argv;
	if (stack_a == NULL)
		die("Error");
	if (make_lst(stack_a))
		die("Error");
	if (argc == 2 && is_split(argv[0]))
	{
//		argc = str_token(&strv, argv[0], ' ');
		argc = str_token(&argv, argv[0], ' ');
		if (argv == NULL)
			die("Error");
	}
//	if (init_stack_a(*stack_a, argc, strv))
	if (init_stack_a(*stack_a, argc, argv))
		die("Error");
//	if (argv != strv)
//		cleanup(strv);
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
	return (FUNC_FAILUER);
}

int	init_stack_a(t_list *stack_a, int argc, char *argv[])
{
	t_list			*sentinel;
	unsigned int	min;
	size_t			i;

	if (stack_a == NULL || argv == NULL)
		return (FUNC_FAILUER);
	sentinel = stack_a;
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

//void	init_stacks(t_list **stack_a, t_list **stack_b, int argc, char *argv[])
//{
//	if (stack_a == NULL || stack_b == NULL || argv == NULL)
//		die("Error");
//	*stack_a = (t_list *)malloc(sizeof(t_list));
//	if (*stack_a == NULL)
//		return ;
//	(*stack_a)->content = NULL;
//	(*stack_a)->prev = *stack_a;
//	(*stack_a)->next = *stack_a;
//	if (init_stack_a(*stack_a, argc, argv))
//		die("Error");
//	*stack_b = (t_list *)malloc(sizeof(t_list));
//	(*stack_b)->content = NULL;
//	(*stack_b)->prev = *stack_b;
//	(*stack_b)->next = *stack_b;
//}
