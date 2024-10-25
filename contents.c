/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:45:37 by sishige           #+#    #+#             */
/*   Updated: 2024/10/25 21:46:42 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstiter_num_to_ternary(t_list *lst, int offset)
{
	t_contents *contents;

	if (lst == NULL)
		return ;
	contents = NULL;
	if (lst->content == NULL)
		lst = lst->next;
	while (lst)
	{
		if (lst->content == NULL)
			break ;
		contents = (t_contents *)lst->content;
		contents->map = mapping(contents->num, offset);
		ulong_to_ternary(contents->ternary, contents->map);
		lst = lst->next;
	}
}

void	free_contents(void *contents)
{
	if (contents == NULL)
		return ;
	free((t_contents *)contents);
	contents = NULL;
}

t_contents	*make_contents(char *str)
{
	if (str == NULL)
		return (NULL);
	t_contents	*contents;
	contents = (t_contents *)malloc(sizeof(t_contents));
	if (contents == NULL)
		return (NULL);
	contents->str = str;
	if (safe_atoi(&contents->num, str))
		return (free(contents), NULL);
	return (contents);
}
