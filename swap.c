/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:06:38 by sishige           #+#    #+#             */
/*   Updated: 2024/10/30 20:44:28 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_content(t_list *a, t_list *b, char *str)
{
	void	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
	if (str)
		ft_printf("%s\n", str);
}

static void	swap_head_and_second(t_list **lst, char *str)
{
	t_list	*sentinel;
	t_list	*head;
	t_list	*second;

	sentinel = *lst;
	head = sentinel->next;
	second = head->next;
	if (sentinel == second)
		return ;
	sentinel->next = second;
	head->prev = second;
	head->next = second->next;
	second->prev = sentinel;
	second->next = head;
	if (str)
		ft_printf("%s\n", str);
}

void	swap_a(t_list **stack_a)
{
	swap_content((*stack_a)->next, (*stack_a)->next->next,"sa");
}

void	swap_b(t_list **stack_b)
{
	swap_content((*stack_b)->next, (*stack_b)->next->next,"sb");
}

void	sa_and_sb(t_list **stack_a, t_list **stack_b)
{
	swap_head_and_second(stack_a, NULL);
	swap_head_and_second(stack_b, "ss");
}
