/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/11/06 20:38:22 by sishige          ###   ########.fr       */
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
	make_stack_a(&stack_a, &argc, a);
	make_lst(&stack_b);
// end

/* EXEC SORT */
// start
	exec_sort(&stack_a, &stack_b, argc);
//	push_a(&stack_a, &stack_b);
//	if (!lst_checker(&stack_a))
//		return (printf("NG"));
//	if (!lst_checker(&stack_b))
//		return (printf("NG"));
//
//	reverse_rotate_a(&stack_a);
//	if (!lst_checker(&stack_a))
//		return (printf("NG"));
//	if (!lst_checker(&stack_b))
//		return (printf("NG"));
//
//	push_a(&stack_a, &stack_b);
//	if (!lst_checker(&stack_a))
//		return (printf("NG"));
//	if (!lst_checker(&stack_b))
//		return (printf("NG"));
//
//	reverse_rotate_b(&stack_b);
//	if (!lst_checker(&stack_a))
//		return (printf("NG"));
//	if (!lst_checker(&stack_b))
//		return (printf("NG"));

// end

// start
// end

/* DEBUG */
// start
//	print_lst("stack_a", &stack_a);
//	print_lst("stack_b", &stack_b);
//	if (is_sorted(stack_a))
//		printf("OK");
//	else
//		printf("NG");
	ft_lstclear(&stack_a, &free_contents);
	ft_lstclear(&stack_b, &free_contents);
// end
	return (0);
}

