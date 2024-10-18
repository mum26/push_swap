/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:33:58 by sishige           #+#    #+#             */
/*   Updated: 2024/10/18 22:08:44 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_list *stack_a, int argc, char *argv[])
{
	
}

void	init_stacks(t_list *stack_a, t_list *stack_b, int argc, char *argv[])
{
	stack_a->content = NULL;
	stack_a->prev = stack_a;
	stack_a->next = stack_a;
	init_stack_a(stack_a, argc, argv);
	stack_b->content = NULL;
	stack_b->prev = stack_b;
	stack_b->next = stack_b;
}

void	print_lst(char const *str, t_list *lst)
{
	printf("[%s] content: %p, current: %p, prev: %p, next: %p\n", \
			str, lst->content, lst, lst->prev, lst->next);
}

int	main(int argc, char *argv[])
{
	t_list	stack_a;
	t_list	stack_b;

	init_stacks(&stack_a, &stack_b, argc, argv);
	return (0);
}

