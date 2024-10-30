/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/10/30 21:02:53 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*current;
	char **a = argv + 1;

	make_stack_a(&stack_a, argc, a);
	make_lst(&stack_b);

	reverse_rotate_a(&stack_a);

	print_lst("stack_a", stack_a);
	current = stack_a->next;
	while (current->content != NULL)
	{
		print_content("stack_a", current);
		current = current->next;
	}
	print_lst("stack_a", current);
	ft_lstclear(&stack_a, &free_contents);

	print_lst("stack_b", stack_b);
	current = stack_b->next;
	while (current->content != NULL)
	{
		print_content("stack_b", current);
		current = current->next;
	}
	print_lst("stack_b", current);
	ft_lstclear(&stack_b, &free_contents);

	return (0);
}

