/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sishige <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 21:10:13 by sishige           #+#    #+#             */
/*   Updated: 2024/10/25 20:36:18 by sishige          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_TERNARY_MAX_LEN 22
# define TER_DIGITS "012"

# define FUNC_SUCCESS 0
# define FUNC_FAILUER 1

# include "libft/libft.h"

typedef struct s_contents
{
	char			*str;
	int				num;
	unsigned int	map;
	char			ternary[INT_TERNARY_MAX_LEN];
}				t_contents;

/* main */
int		make_stack_a(t_list **stack_a, int argc, char *argv[]);
/* make_stack_a */
int		init_stack_a(*stack_a, )

int		exec_sort(t_list **stack_a, t_list **stack_b);
int		cleaning_up(t_list **stack_a, t_list **stack_b);


void	die(char *cause);

void	print_lst(char const *str, t_list *lst);

#endif
