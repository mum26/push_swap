/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 20:06:38 by sishige           #+#    #+#             */
/*   Updated: 2024/10/29 20:34:30 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char *str)
{
	t_list	*temp;

	temp = *lst;
	*lst = (*lst)->next;
	(*lst)->prev = temp->prev;
	temp->prev = *lst;
	temp->next = (*lst)->next;
	(*lst)->next = temp;
	if (str)
		ft_printf("%s\n", str);
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a, "sa");
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b, "sb");
}

void	sa_and_sb(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, NULL);
	swap(stack_b, "ss");
}
