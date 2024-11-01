/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:43:36 by sishige           #+#    #+#             */
/*   Updated: 2024/11/01 22:22:42 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b, size_t n)
{
	while (n--)
	{
		push_a(stack_a, stack_b);
		push_b(stack_b, stack_a);
	}
	return ;
}

void	sort_three(t_list **lst)
{
	t_list	*head;
	t_list	*next;
	t_list	*tail;

	head = (*lst)->next;
	next = head->next;
	tail = (*lst)->prev;
	if (((t_contents *)head->content)->map < ((t_contents *)next->content)->map)
	{
		if (((t_contents *)tail->content)->map > ((t_contents *)head->content)->map)
			swap_a(lst);
		reverse_rotate_a(lst);
	}
	else
	{
		if (((t_contents *)next->content)->map < ((t_contents *)tail->content)->map)
		{
			if (((t_contents *)tail->content)->map > ((t_contents *)head->content)->map)
				reverse_rotate_a(lst);
			else
				swap_a(lst);
		}
		else
		{
			swap_a(lst);
			reverse_rotate_a(lst);
		}
	}
}

//void	sort_four(t_list **stack_a)
//{
//
//}
//
//void	sort_five(t_list **stack_a)
//{
//
//}
//
//void	sort_six(t_list **stack_a)
//{
//
//}

void	exec_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list *next_a;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	next_a = (*stack_a)->next;
	if (argc == 2 || is_sorted(*stack_a))
		return;
	else if (argc == 3)
	{
		if (((t_contents *)next_a->content)->map
			> ((t_contents *)next_a->next->content)->map)
			swap_a(stack_a);
	}
	else if (argc == 4)
		sort_three(stack_a);
//	else if (argc == 5)
//		sort_four(stack_a);
//	else if (argc == 6)
//		sort_five(stack_a);
//	else if (argc == 7)
//		sort_six(stack_a);
	else
		radix_sort(stack_a, stack_b, get_num_of_digit_base(argc - 1, 3));
}

