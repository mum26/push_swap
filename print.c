/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:17:44 by sishige           #+#    #+#             */
/*   Updated: 2024/11/01 19:22:52 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_lst(char const *str, t_list *lst)
{
	t_list	*current;

	if (str == NULL || lst == NULL)
		return ;
	current = lst->next;
	while (current->content != NULL)
	{
		print_content(str, current);
		current = current->next;
	}
}

void	print_node(char const *str, t_list *node)
{
	printf("[%s] content: %15p, prev: %15p, current: %15p, next: %15p\n", 
			str, node->content, node, node->prev, node->next);
}

void	print_content(char const *str, t_list *lst)
{
	t_contents *c;

	c = (t_contents *)lst->content;
	if (c == NULL)
	{
		printf("[%s] sentinel\n", str);
		return ;
	}
	printf("[%s] num: %11d, map: %11u, ternary: %s\n",
			str, c->num, c->map, c->ternary);
}
