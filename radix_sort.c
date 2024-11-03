/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:43:22 by sishige           #+#    #+#             */
/*   Updated: 2024/11/03 23:21:37 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list **stack_a, t_list **stack_b, int argc)
{
	t_contents	*cont_a;
	size_t		digit = get_num_of_digit_base(argc, 3);
	printf("%ld\n", digit);
	int			i;
	int			zero;
	int			one;
	int			two;

	cont_a = (t_contents *)(*stack_a)->next->content;
	while (digit--)
	{
		zero = 0;
		one = 0;
		two = 0;
		i = 0;
		while (i < argc)
		{
			if (cont_a->ternary[digit] == '0')
			{
				rotate_a(stack_a);
				zero++;
			}
			if (cont_a->ternary[digit] == '1')
			{
				push_a(stack_a, stack_b);
				one++;
			}
			if (cont_a->ternary[digit] == '2')
			{
				push_a(stack_a, stack_b);
				reverse_rotate_b(stack_b);
				two++;
			}
			cont_a = (t_contents *)(*stack_a)->next->content;
			i++;
		}
		while (two--)
		{
			rotate_b(stack_b);
			push_b(stack_b, stack_a);
		}
		while (one--)
		{
			push_b(stack_b, stack_a);
		}
		while (zero--)
			reverse_rotate_a(stack_a);
	}
}

//void	radix_sort(t_list **stack_a, t_list **stack_b, int argc)
//{
//	t_contents		*cont_a;
//	size_t		j;
//	size_t		digit = get_num_of_digit_base(argc, 3) - 1;
//	int			zero;
//	int			one;
//	int			two;
//	int			cnt_b;
//
//	cont_a = (t_contents *)(*stack_a)->next->content;
//	while (digit--)
//	{
//		j = 0;
//		zero = 0;
//		one = 0;
//		two = 0;
//		cnt_b = 0;
//		while (j < (size_t)argc)
//		{
//			if (cont_a->ternary[digit] == '0')
//			{
//				if (argc - cnt_b != 1)
//					rotate_a(stack_a);
//				zero++;
//			}
//			else if (cont_a->ternary[digit] == '1')
//			{
//				push_a(stack_a, stack_b);
//				cnt_b++;
//				one++;
//			}
//			else
//			{
//				push_a(stack_a, stack_b);
//				cnt_b++;
//				if (cnt_b < 3)
//					swap_b(stack_b);
//				else if (cnt_b != 1)
//					reverse_rotate_b(stack_b);
//				two++;
//			}
//			cont_a = (t_contents *)(*stack_a)->next->content;
//			j++;
//		}
//		while (two--)
//		{
//			if (cnt_b < 3)
//				swap_b(stack_b);
//			else if (cnt_b != 1)
//				rotate_b(stack_b);
//			push_b(stack_b, stack_a);
//			cnt_b--;
//		}
//		while (one--)
//		{
//			push_b(stack_b, stack_a);
//			cnt_b--;
//		}
//		while (zero--)
//			reverse_rotate_a(stack_a);
//	}
//}

