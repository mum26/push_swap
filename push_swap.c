/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/10/25 23:06:22 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_sentinel(t_list **lst)
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

void	make_stack_a(t_list **stack_a, int argc, char *argv[])
{
	if (stack_a == NULL)
		die("Error");
	if (make_sentinel(stack_a))
		die("Error");
	if (init_stack_a(*stack_a, argc, argv))
		die("Error");
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

