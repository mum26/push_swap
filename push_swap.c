/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/10/28 20:47:08 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*current;

	make_stack_a(&stack_a, argc, argv + 1);
	print_lst("stack_a", stack_a);
	current = stack_a->next;
	while (current->content != NULL)
	{
		print_content("stack_a", current);
		current = current->next;
	}
	print_lst("stack_a", current);
	ft_lstclear(&stack_a, &free_contents);
	return (0);
}

