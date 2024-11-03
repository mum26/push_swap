/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:15:02 by sishige           #+#    #+#             */
/*   Updated: 2024/11/03 22:49:03 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_list **lst, char *str)
{
	t_list	*head;
	t_list	*next;
	t_list	*tail;

	head = (*lst)->next;
	tail = (*lst)->prev;
	if ((*lst == tail) || (head == tail))
		return ;
	next = head->next;
	(*lst)->prev = head;
	(*lst)->next = next;
	head->prev = tail;
	head->next = (*lst);
	next->prev = (*lst);
	tail->next = head;
	if (str)
		ft_printf("%s\n", str);
}

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a, "ra");
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b, "rb");
}

void	ra_and_rb(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, "rr");
}
