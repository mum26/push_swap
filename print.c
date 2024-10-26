/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:17:44 by sishige           #+#    #+#             */
/*   Updated: 2024/10/25 19:28:13 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(char const *str, t_list *lst)
{
	printf("[%s] content: %15p, prev: %15p, current: %15p, next: %15p\n", 
			str, lst->content, lst, lst->prev, lst->next);
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
	printf("[content] argv: %11s, num: %11d, map: %11u, ternary: %s\n",
			c->str, c->num, c->map, c->ternary);
}
