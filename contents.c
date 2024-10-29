/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:45:37 by sishige           #+#    #+#             */
/*   Updated: 2024/10/29 17:09:23 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstiter_num_to_ternary(t_list *lst, int offset)
{
	t_contents *contents;

	if (lst == NULL)
		return (FUNC_FAILUER);
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
	return (FUNC_SUCCESS);
}

void	free_contents(void *contents)
{
	if (contents == NULL)
		return ;
	free((t_contents *)contents);
	contents = NULL;
}

int	is_duplicate(int n, t_list *sentinel)
{
	t_list	*current;
	if (sentinel == NULL)
		return (FUNC_FAILUER);
	current = sentinel->next;
	while (current)
	{
		if (current->content == NULL)
			break ;
		if (((t_contents *)current->content)->num == n)
			return (printf("%d\n", n), FUNC_FAILUER);
		current = current->next;
	}
	return (FUNC_SUCCESS);
}

t_contents	*make_contents(char *str, t_list *sentinel)
{
	int	temp;
	if (str == NULL)
		return (NULL);
	t_contents	*contents;
	contents = (t_contents *)malloc(sizeof(t_contents));
	if (contents == NULL)
		return (NULL);
	contents->str = str;
	if (safe_atoi(&temp, str))
		return (free(contents), NULL);
	if (is_duplicate(temp, sentinel))
		return (free(contents), NULL);
	contents->num = temp;
	return (contents);
}
