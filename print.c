/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:17:44 by sishige           #+#    #+#             */
/*   Updated: 2024/11/21 18:03:33 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(char const *str, t_list **lst)
{
	t_list	*current;

	current = NULL;
	if (str == NULL || lst == NULL || *lst == NULL)
		return ;
	current = *lst; // 番兵ノードを開始ノードとする
	do
	{
		// ノードのアドレスを参照するために &current を渡す
//		print_node(str, &current);
		print_content(str, current);
		current = current->next;
	} while (current != *lst); // 開始ノードに戻ったら終了
}

void	print_node(char const *str, t_list **node)
{
	printf("[%s] content: %p, prev: %p, current: %p, next: %p\n", str,
		(*node)->content, (void *)(*node)->prev, (void *)(*node),
		(void *)(*node)->next);
}

void	print_content(char const *str, t_list *lst)
{
	t_contents	*c;
	(void)str;

	c = (t_contents *)lst->content;
	if (c == NULL)
		return ;
	printf("[%s] num: %d, map: %u, digits: %s\n",
			"c", c->num, c->map, c->digits_str);
}

// void		print_lst(char const *str, t_list **lst)
//{
//	t_list	*current;
//
//	if (str == NULL || lst == NULL)
//		return ;
//	print_node("番兵", lst);
//	current = (*lst)->next;
//	while (current != *lst)
//	{
//		print_node(str, lst);
//		print_content(str, current);
//		current = (*lst)->next;
//	}
//}
//
// void	print_node(char const *str, t_list **node)
//{
//	printf("[%s] content: %15p, prev: %15p, current: %15p, next: %15p\n",
//			str, (*node)->content, (*node), (*node)->prev, (*node)->next);
//}
//
// void	print_content(char const *str, t_list *lst)
//{
//	t_contents *c;
//
//	c = (t_contents *)lst->content;
//	if (c == NULL)
//	{
//		printf("[%s] sentinel\n", str);
//		return ;
//	}
//	printf("[%s] num: %11d, map: %11u, ternary: %s\n",
//			str, c->num, c->map, c->ternary);
//}
