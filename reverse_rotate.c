/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:57:06 by sishige           #+#    #+#             */
/*   Updated: 2024/10/30 21:03:44 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_list **lst, char *str)
{
	t_list	*head;
	t_list	*prev;
	t_list	*tail;

	head = (*lst)->next;
	tail = (*lst)->prev;
	prev = tail->prev;
	if (*lst == tail)
		return ;
	(*lst)->prev = prev;
	(*lst)->next = tail;
	head->prev = tail;
	prev->next = *lst;
	tail->prev = *lst;
	tail->next = head;
	if (str)
		ft_printf("%s\n", str);
}

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate(stack_a, "rra");
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate(stack_b, "rrb");
}

void	rra_and_rrb(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, "rrr");
}
