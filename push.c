/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:04:01 by sishige           #+#    #+#             */
/*   Updated: 2024/11/06 19:02:22 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	push_left_to_right(t_list **left, t_list **right, char *str)
{
	t_list	*lst[LR];
	t_list	*head[LR];
	t_list	*next[LR];
	t_list	*tail[LR];

	lst[L] = *left;
	head[L] = lst[L]->next;
	next[L] = head[L]->next;
	tail[L] = lst[L]->prev;

	lst[R] = *right;
	head[R] = lst[R]->next;
	next[R] = head[R]->next;
	tail[R] = lst[R]->prev;

	if (lst[L] == lst[L]->next)
		return ;

	lst[L]->next = next[L];
	next[L]->prev = lst[L];
	if (next[L] == lst[L])
		lst[L]->prev = lst[L];

	lst[R]->next = head[L];
	head[L]->prev = lst[R];
	head[L]->next = head[R];
	head[R]->prev = head[L];
	if (tail[R] == lst[R])
		lst[R]->prev = head[L];

	if (str)
		ft_printf("%s\n", str);
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push_left_to_right(stack_a, stack_b, "pa");
}

void	push_b(t_list **stack_b, t_list **stack_a)
{
	push_left_to_right(stack_b, stack_a, "pb");
}
