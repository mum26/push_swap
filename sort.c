/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:43:36 by sishige           #+#    #+#             */
/*   Updated: 2024/11/03 18:46:00 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **lst)
{
	t_list	*head;
	t_list	*next;
	t_list	*tail;

	while (!is_sorted(*lst))
	{
		head = (*lst)->next;
		next = head->next;
		tail = (*lst)->prev;
		if (((t_contents *)head->content)->map < ((t_contents *)next->content)->map 
				&& ((t_contents *)next->content)->map > ((t_contents *)tail->content)->map 
				&& ((t_contents *)tail->content)->map < ((t_contents *)head->content)->map)
			reverse_rotate_a(lst);
		else if (((t_contents *)head->content)->map > ((t_contents *)next->content)->map 
				&& ((t_contents *)next->content)->map < ((t_contents *)tail->content)->map 
				&& ((t_contents *)tail->content)->map < ((t_contents *)head->content)->map)
			rotate_a(lst);
		else
			swap_a(lst);
	}
}

void	sort_six(t_list **stack_a, t_list **stack_b, int argc)
{
	size_t	i;
	int		is_ra;

	i = 0;
	is_ra = 1;
	if (((t_contents *)(*stack_a)->prev->content)->map == i)
		is_ra = 0;
	while (3 < argc - 1)
	{
		if (((t_contents *)(*stack_a)->next->content)->map == i)
		{
			push_a(stack_a, stack_b);
			argc--;
			i++;
		}
		else
		{
			if (is_ra)
				rotate_a(stack_a);
			else
				reverse_rotate_a(stack_a);
		}
	}
	sort_three(stack_a);
	while (i--)
		push_b(stack_b, stack_a);
}

void	exec_sort(t_list **stack_a, t_list **stack_b, int argc)
{
//	t_list *next_a;

	if (stack_a == NULL || stack_b == NULL)
		return ;
//	next_a = (*stack_a)->next;
//	if (argc == 2 || is_sorted(*stack_a))
//		return;
//	else if (argc == 3)
//	{
//		if (((t_contents *)next_a->content)->map
//			> ((t_contents *)next_a->next->content)->map)
//			swap_a(stack_a);
//	}
//	else if (argc == 4)
//		sort_three(stack_a);
//	else if (argc <= 7)
//		sort_six(stack_a, stack_b, argc);
//	else
		radix_sort(stack_a, stack_b, argc - 1);
}

