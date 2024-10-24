/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:17:44 by sishige           #+#    #+#             */
/*   Updated: 2024/10/24 17:19:09 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(char const *str, t_list *lst)
{
	t_contents *c;

	printf("[%s] content: %15p, current: %p, prev: %p, next: %p\n", \
			str, lst->content, lst, lst->prev, lst->next);
	c = (t_contents *)lst->content;
	if (c == NULL)
		return ;
	printf("\t[content] argv: %s, num: %d\n",
			c->str, c->num);
}

