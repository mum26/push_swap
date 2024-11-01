/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contents.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:45:37 by sishige           #+#    #+#             */
/*   Updated: 2024/11/01 18:41:11 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstiter_num_to_ternary(t_list *stack_a)
{
	t_list	*current;
	t_list	*lst;
	size_t	cnt;

	if (stack_a == NULL)
		return (FUNC_FAILUER);
	if (stack_a->content == NULL)
		stack_a = stack_a->next;
	current = stack_a;
	while (current->content)
	{
		lst = stack_a;
		cnt = 0;
		while (lst->content)
		{
			if (((t_contents *)lst->content)->num < ((t_contents *)current->content)->num)
				cnt++;
			lst = lst->next;
		}
		((t_contents *)current->content)->map = cnt;
		((t_contents *)current->content)->ternary = ft_ulltoa_base(cnt, TER_DIGITS);
		current = current->next;
	}
	return (FUNC_SUCCESS);
}

void	free_contents(void *contents)
{
	if (contents == NULL)
		return ;
	if (((t_contents *)contents)->ternary)
	{
		free(((t_contents *)contents)->ternary);
		((t_contents *)contents)->ternary = NULL;
	}
	free((t_contents *)contents);
	contents = NULL;
}


t_contents	*make_contents(char *str, t_list *sentinel)
{
	int			temp;
	t_contents	*contents;

	if (str == NULL)
		return (NULL);
	contents = (t_contents *)malloc(sizeof(t_contents));
	if (contents == NULL)
		return (NULL);
	if (safe_atoi(&temp, str))
		return (free(contents), NULL);
	if (is_duplicate(temp, sentinel))
		return (free(contents), NULL);
	contents->num = temp;
	contents->map = 0;
	contents->ternary = NULL;
	return (contents);
}
