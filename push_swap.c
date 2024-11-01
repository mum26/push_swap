/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/11/01 18:39:49 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char **a = argv + 1;

/* MAKE STACK A */
// start
	make_stack_a(&stack_a, argc, a);
	make_lst(&stack_b);
// end

/* EXEC SORT */
// start
	push_a(&stack_a, &stack_b);
// end

/* CLEANING UP */
// start
// end

/* DEBUG */
// start
	print_lst("stack_a", stack_a);
	print_lst("stack_b", stack_b);
	ft_lstclear(&stack_b, &free_contents);
	ft_lstclear(&stack_b, &free_contents);
// end

	return (0);
}

